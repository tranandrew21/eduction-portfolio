#include "Puzzle.hpp"
#include <vector>
#include <stack>
#include <iostream>
#include <algorithm>
using namespace std;

// Began using iterators to shorten the writing of for loops. 

Puzzle::Puzzle(int n){
    //TODO
    this->n = n;
}

void Puzzle::addEdge(int v1, int v2) {
    // Variables
    vertex* ver1;
    vertex* ver2;

    bool ver1Check = false;
    bool ver2Check = false;
    
    // Using iterator to iterate through vertices size. - Idea taken from the recitation functions. 
    for(vertex* it : vertices) {
        if(it->vertexNum == v1) {
            ver1 = it;
        }
        else if(it->vertexNum == v2) {
            ver2 = it;
        }
    }
    for(adjVertex it : ver1->adj) {
        if(it.v == ver2) {
            ver2Check = true;
            break;
        }
    }
    for(adjVertex it : ver2->adj) {
        if(it.v == ver1) {
            ver1Check = true;
            break;
        }
    }
    if(ver2Check == false) {
        ver1->adj.push_back(adjVertex{ver2});
    }
    if(ver1Check == false) {
        ver2->adj.push_back(adjVertex{ver1});
    }
}

void Puzzle::addVertex(int num){
    //TODO
    bool found = false;
    for (vertex* it : vertices) {
        if (it -> vertexNum == num) {
            found = true;
            break;
        }
    }
    if (found == false) {
        vertex* v = new vertex;
        v->vertexNum = num;
        vertices.push_back(v);
    }
}

void Puzzle::displayEdges() {
    //TODO
    for(vertex* it : vertices) {
        cout << it->vertexNum << " --> ";
        for (adjVertex it2 : it->adj) {
            cout << it2.v->vertexNum << " ";
        }
        cout << endl;
    }
}

// Finds the vertex number from the position of the open path in the maze
int Puzzle::findVertexNumFromPosition(int x, int y) {
    //TODO
    if(x > n || y > n || x < 0 || y < 0) {
        return -1;
    }
    else {
        int ans = y + n * x;
        return ans;
    }
}

void Puzzle::createDefaultPuzzle() {
    //TODO
    puzzle = new int*[n];
    for(int i = 0; i < n; i++) {
        puzzle[i] = new int[n];
        for(int j = 0; j < n; j++) {
            puzzle[i][j] = 1;
        }
    }

    createPath(0,0);
    createPath(n - 1, n - 1);
}

void Puzzle::createPath(int i, int j) {
    //TODO
    // Constraints
    if(i < n && j < n && i >= 0 && j >= 0) {
        puzzle[i][j] = 0;
    }
}

void Puzzle::printPuzzle() {
    //TODO
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << "| " << puzzle[i][j] << " ";
        }
        cout << "|" << "\n";
    }
}

vector<int> Puzzle::findOpenAdjacentPaths(int x, int y) {
    vector<int> neighbors; 

    for(int i = x-1; i <= x + 1; i++) {
        if(i < 0 || i >= n) {
            continue;
        }
        for(int j = y-1; j <= y+1; j++){
            if(j < 0 || j >= n) {
                continue;
            }
            if(!(i == x && j == y) && puzzle[i][j] == 0) {
                neighbors.push_back(findVertexNumFromPosition(i, j));
            }
        }
    }
    return neighbors;
}

void Puzzle::convertPuzzleToAdjacencyListGraph() {
    //TODO
    vector<int> adjList;
    int nodes;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(puzzle[i][j] == 0) {
                nodes = findVertexNumFromPosition(i,j);
                addVertex(nodes);
            }
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(puzzle[i][j] == 0) {
                nodes = findVertexNumFromPosition(i,j);
                adjList = findOpenAdjacentPaths(i,j);
                for(int it : adjList) {
                    addEdge(it, nodes);
                }
            }
        }
    }
    return;
}
bool pathHelperFunc(vertex* v, int n, vector<int>* p) {
    bool found;

    v->visited = true;
    cout << "Reached vertex: " << v->vertexNum << endl;

    for(adjVertex it : v->adj) {
        if(v->vertexNum == n) {
            (*p).push_back(v->vertexNum);
            return true;
        }
        if(it.v->visited == false) {
            found = pathHelperFunc(it.v, n, p);

            if(found) {
                (*p).push_back(v->vertexNum);
                return true;
            }
            else {
                cout << "Backtracked to vertex: " << v->vertexNum << endl;
            }
        }            
    }
    return false;  
}
bool Puzzle::findPathThroughPuzzle() {
    //TODO
    vertex* begin = vertices.front();

    cout << "Starting at vertex: " << begin->vertexNum << endl;
    bool found = pathHelperFunc(begin, n * n - 1, &path);

    if(found == true) {
        reverse(path.begin(), path.end());
    }
    return found;
}

bool isValidHelper(vector<vertex*>* vertices, int v1, int v2) {
    for(vertex* it : *vertices) {
        if(v1 == it->vertexNum) {
            for(adjVertex it2 : it->adj) {
                if(v2 == it2.v->vertexNum) {
                    return true;
                }
            }
            return false;
        }
    }
    return false;
}

bool Puzzle::checkIfValidPath() {
    //TODO

    if(path.size() == 0 || path.front() != 0 || path.back() != n * n - 1) {
        return false;
    }
    for(unsigned int i = 1; i < path.size(); i++) {
        if(isValidHelper(&vertices, path[i - 1], path[i]) == false) {
            return false;
        }
    }
    return true;
}

Puzzle::~Puzzle() {
    //TODO
    if (n > 0) {
        for(int i = 0; i < n; i++) {
            delete[] puzzle[i];
        }
        delete[] puzzle;
    }
    for (unsigned int i = 0; i< vertices.size(); i++) {
        delete vertices[i];  
    }
}

