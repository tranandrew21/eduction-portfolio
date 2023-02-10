#include "ShowCatalog.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

/* Completed functions. DO NOT MODIFY*/
ShowCatalog::ShowCatalog()
{
    root = nullptr;
}

/* Completed functions. DO NOT MODIFY*/
void destroyNode(ShowItem *current)
{
    if (current != nullptr)
    {
        destroyNode(current->left);
        destroyNode(current->right);

        delete current;
        current = nullptr;
    }
}

/* Completed functions. DO NOT MODIFY*/
ShowCatalog::~ShowCatalog()
{
    destroyNode(root);
}

/* Completed functions. DO NOT MODIFY*/
void printShowHelper(ShowItem *m)
{
    if (m != nullptr)
    {
        cout << "Show: " << m->title << " " << m->userRating << endl;
        printShowHelper(m->left);
        printShowHelper(m->right);
    }
}

/* Completed functions. DO NOT MODIFY*/
void ShowCatalog::printShowCatalog()
{
    if (root == nullptr)
    {
        cout << "Tree is Empty. Cannot print" << endl;
        return;
    }
    printShowHelper(root);
}

/* Completed functions. DO NOT MODIFY*/
ShowItem *getShowHelper(ShowItem *current, string title)
{
    if (current == NULL)
        return NULL;

    if (current->title == title)
        return current;

    if (current->title > title)
        return getShowHelper(current->left, title);

    return getShowHelper(current->right, title);
}

/* Completed functions. DO NOT MODIFY*/
void ShowCatalog::getShow(string title)
{
    ShowItem *node = getShowHelper(root, title);
    if (node != nullptr)
    {
        cout << "Show Info:" << endl;
        cout << "==================" << endl;
        cout << "Title :" << node->title << endl;
        cout << "Year :" << node->year << endl;
        cout << "Show Rating :" << node->showRating << endl;
        cout << "User Rating :" << node->userRating << endl;
        return;
    }

    cout << "Show not found." << endl;
}

/* Completed functions. DO NOT MODIFY*/
ShowItem *addNodeHelper(ShowItem *current, ShowItem *newNode)
{
    if (current == nullptr)
    {
        return newNode;
    }

    if (current->title > newNode->title)
    {
        current->left = addNodeHelper(current->left, newNode);
    }
    else
    {
        current->right = addNodeHelper(current->right, newNode);
    }

    return current;
}

/* Completed functions. DO NOT MODIFY*/
void ShowCatalog::addShowItem(string title, int year, string showRating, float userRating)
{
    if (root == nullptr)
    {
        root = new ShowItem(title, year, showRating, userRating);
        return;
    }

    root = addNodeHelper(root, new ShowItem(title, year, showRating, userRating));
}
// minValue node
ShowItem* ShowCatalog::minValueNode(ShowItem* node){
    ShowItem* curr = node;
    while(curr && curr -> left != NULL) {
        curr = curr->left;
    }
    return curr;
}

// removeShow helper
ShowItem* ShowCatalog::deleteHelper(ShowItem* node, string title) {
    // Base Case
    if (node == nullptr) {
        return node;
    }
    // If show to be deleted 
    // is smaller then root's
    // then it is in left subtree
    // recursion into left subtree
    if(title < node -> title) {
        node -> left = deleteHelper(node ->left, title);
    }
    // If show to delete 
    // greater then root
    // is in right subtree
    else if(title > node -> title) {
        node -> right = deleteHelper(node -> right, title);
    }
    // If the show is the same as the root show
    // This show is the one to be deleted
    else {
        // Check if node has no child
        if (node -> left == NULL && node -> right == NULL) {
            delete(node);
            return NULL;
        }
        // If node only has one child or no child
        else if (node -> left == NULL) {
            ShowItem* temp = node -> right;
            delete(node);
            return temp;
        }
        else if (node -> right  == NULL) {
            ShowItem* temp = node -> left;
            delete(node);
            return temp;
        }   
        // Node with two children - inorder successor
        // aka (Smallest in the subtree)
        ShowItem* temp = minValueNode(node -> right);

        node -> title = temp -> title;
        node -> showRating = temp -> showRating;
        node -> userRating = temp -> userRating;
        node -> year = temp -> year;
        node -> right = deleteHelper(node->right, temp->title);
    }
    return node;
}

/* TODO */
void ShowCatalog::removeShow(std::string title)
{
    // TODO
    root = deleteHelper(root, title);
}


ShowItem* rightRotateHelp(ShowItem* node, string title);
ShowItem* rightRotateHelp(ShowItem* node, string title) {
    if(node == NULL) {
        return node;
    }

    if(node -> title < title) {
        node -> right = rightRotateHelp(node -> right, title);
    }
    else if(node -> title > title ) {
        node -> left = rightRotateHelp(node -> left, title);
    }
    else {
        ShowItem* nn = node;
        node = node -> left;
        nn -> left = node -> right;
        node -> right = nn;
    }
    return node;
}




/* TODO */
void ShowCatalog::rightRotate(std::string title)
{
    // TODO
    root = rightRotateHelp(root, title);
}




ShowItem* ShowCatalog::leftRotateHelp(ShowItem* node, string title) {
    if(node == NULL) {
        return node;
    }

    if(node -> title < title) {
        node -> right = leftRotateHelp(node -> right, title);
    }
    else if(node -> title > title ) {
        node -> left = leftRotateHelp(node -> left, title);
    }
    else {
        ShowItem* nn = node;
        node = node -> right;
        nn -> right = node -> left;
        node -> left = nn;
    }
    return node;
}




/* TODO */
void ShowCatalog::leftRotate(std::string title)
{
    // TODO
    root = leftRotateHelp(root, title);
}
