#include "ShowCatalog.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;




ShowCatalog::ShowCatalog() {
    root = nullptr;
}

void ShowCatalog::destroyRecursive(ShowItem* node) {
    if(node) {
        destroyRecursive(node -> left);
        destroyRecursive(node -> right);
        delete node;
    }
}

ShowCatalog::~ShowCatalog() {
    destroyRecursive(root);
}

void ShowCatalog::printCatalogHelp(ShowItem* node) {
    if (node == NULL) {
        return;
    }
    cout << "Show: " << node -> title << " " << node -> userRating << endl;
    printCatalogHelp(node -> left);
    printCatalogHelp(node -> right);


}

void ShowCatalog::printShowCatalog() {
    // TODO
    if (root == NULL) {
        cout << "Tree is Empty. Cannot print" << endl;
    }
    printCatalogHelp(root);
}

ShowItem* ShowCatalog::getHelper(ShowItem* node, string title) {
    if (node && node -> title == title) {
        cout << "Show Info:" << endl;
        cout << "==================" << endl;
        cout << "Title :" << node->title << endl;
        cout << "Year :" << node->year << endl;
        cout << "Show Rating :" << node->showRating << endl;
        cout << "User Rating :" << node->userRating << endl;
    }
    else if (node && node -> title < title) {
        getHelper(node -> right, title);
    }
    else if (node && node -> title > title) {
        getHelper(node -> left, title);
    }
    else cout << "Show not found." << endl; 
}

void ShowCatalog::getShow(string title) {
    // TODO
    getHelper(root, title);
}

ShowItem* ShowCatalog::addHelper(ShowItem* node, string title, int year, string showRating, float userRating) {

    if (title > node -> title) {
        if (node -> right) {
            addHelper(node -> right,title, year, showRating, userRating);
        }
        else {
            node -> right = new ShowItem(title, year, showRating, userRating);
        }
    }
    else if (title < node -> title) {
        if(node -> left) {
            addHelper(node -> left, title, year, showRating, userRating);
        }
        else {
            node -> left = new ShowItem(title, year, showRating, userRating);
        }
    }
    // return node;
}

void ShowCatalog::addShowItem(string title, int year, string showRating, float userRating) {
    // TODO
    if (root == NULL) {
        root = new ShowItem(title, year, showRating, userRating);
    }
    else {
        addHelper(root,title, year, showRating, userRating);
    }
}

void ShowCatalog::leafHelper(ShowItem* node) {
    if (node == NULL) {
        return;
    }
    if (node -> left == NULL && node -> right == NULL) {
        cout << node -> title << endl;
    }
    if (node -> left) {
        leafHelper(node -> left);
    }
    if(root -> right) {
        leafHelper(node -> right);
    }
}

void ShowCatalog::printLeafNodes() {
    // TODO
    leafHelper(root);
}

ShowItem* ShowCatalog::searchHelper(ShowItem* node, char title) {
    if (node) {
        if(node -> title[0] == title) {
            cout << node -> title << "(" << node -> year << ") " << node -> userRating << endl;
        }
        searchHelper(node -> left, title);
        searchHelper(node -> right, title);
    }
}

void ShowCatalog::searchShows(char titleChar) {
    // TODO
    if (root == NULL) {
        cout << "Tree is Empty. Cannot search Shows" << endl;
    }
    cout << "Shows that starts with " << titleChar << ":" << endl;
    searchHelper(root, titleChar);
}

void ShowCatalog::numHelper(ShowItem* node, int&count, string showRating) {
    if (node) {
        if(node -> showRating == showRating) count++;
        numHelper(node->left, count, showRating);
        numHelper(node -> right, count, showRating);
    }

}

void ShowCatalog::displayNumShowRating(int &count, string showRating) {
    // TODO
    numHelper(root, count, showRating);
}
