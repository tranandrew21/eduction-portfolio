#include "Graph.hpp"
#include <vector>
#include <bits/stdc++.h>
#include <queue>
#include <iostream>

using namespace std;

void Graph::addVertex(string name){
    //TODO
    bool found = false;
    for (int i = 0; i < vertices.size(); i++) {
        if (vertices[i] -> name == name) {
            found = true;
            break;
        }
    }
    if (found == false) {
        vertex* v = new vertex;
        v->name = name;
        vertices.push_back(v);
    }

}

void Graph::addEdge(string v1, string v2){
    //TODO
    for (int x = 0; x < vertices.size(); x++) {
        if(vertices[x]->name == v1) {
            for (int y = 0; y < vertices.size();y++) {
                if (vertices[y] -> name == v2) {
                    adjVertex av;
                    av.v = vertices[y];
                    vertices[x]->adj.push_back(av);

                    adjVertex av2;
                    av2.v = vertices[x];
                    vertices[y]->adj.push_back(av2);
                }
            }
        }
    }
}


void Graph::displayEdges(){
    //TODO
    for(int i = 0; i < vertices.size(); i++) {
        cout << vertices[i]->name << " --> ";
        for (int j = 0; j < vertices[i]->adj.size();j++) {
            cout << vertices[i]->adj[j].v->name << " ";
        }
        cout << endl;
    }
}

void Graph::breadthFirstTraverse(string sourceVertex){
    //TODO
    queue<vertex*> q;
    vertex* vStart;  
    for(int i = 0; i < vertices.size();i++) {
        if(vertices[i]->name == sourceVertex) {
            vStart = vertices[i];
            break;
        }
    }
    vStart->visited = true;
    q.push(vStart);
    cout << "Starting vertex (root): " << vStart-> name << "-> ";
    
    while(!q.empty()) {
        auto it = q.front();
        q.pop();
        for(auto it2:it->adj) {
            if (it2.v -> visited == false) {
                it2.v -> visited = true;
                it2.v -> distance = it -> distance + 1;
                cout << it2.v->name <<"("<< it2.v->distance <<")"<< " ";
                q.push(it2.v);
            }
        }
    }
    cout << "\n" <<endl;

}



/*
string::source : source vertex (starting city)
int::k : distance that you can travel from source city with remaining fuel
*/
vector<string> Graph::findReachableCitiesWithinDistanceK(string source, int k){
    queue<vertex*> q;
    vertex* vStart;  
    vector<string> cities;
    for(int i = 0; i < vertices.size();i++) {
        if(vertices[i]->name == source) {
            vStart = vertices[i];
            break;
        }
    }
    vStart->visited = true;
    vStart->distance = 0;
    q.push(vStart);
    // cities.push_back(vStart->name);
    vertex* n;
    while(!q.empty()) {
        n = q.front();
        q.pop();
        for(int i = 0; i < n->adj.size(); i++) {
            if(!n->adj[i].v->visited) {
                n-> adj[i].v->distance = n->distance + 1;
                n-> adj[i].v->visited = true;
                q.push(n->adj[i].v);
            }
            
        }
    }
    for(int i = 0; i < vertices.size(); i++) {
        if(vertices[i]->distance == k) {
            cities.push_back(vertices[i]->name);
        }
    }
    return cities;    
}
