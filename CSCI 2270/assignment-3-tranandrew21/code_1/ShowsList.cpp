/*************************************************************/
/*                   ShowsList Definition                    */
/*************************************************************/
/* TODO: Implement the member functions of class ShowsList   */
/*     This class uses a linked-list of Show structs to      */
/*     represent the schedule of shows                       */
/*************************************************************/

#include "ShowsList.hpp"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

using namespace std;

/*
 * Purpose: Constructor for empty linked list
 * @param none
 * @return none
 */
ShowsList::ShowsList() {
    /*
    DO NOT MODIFY THIS
    This constructor is already complete. 
    */
    head = nullptr;
}

/*
 * Purpose: Check if list is empty
 * @return true if empty; else false
 */
bool ShowsList::isEmpty() {
    /* finished. do not touch. */
    return (head == NULL);
}

/*
 * Purpose: prints the current list of shows nicely
 * @param none
 * @return none
 */
void ShowsList::displayShows() {
    // TODO
    Show* newNode = head;
    if (isEmpty() == false) {
        cout << "== CURRENT SHOWS LIST ==" << "\n";
        while(newNode != nullptr) {
            cout << newNode -> name << "-> ";
            newNode = newNode -> next;
        }
        cout << "NULL" << "\n";
        cout << "===" << "\n";
    }
    else {
        // cout << "== CURRENT SHOWS LIST ==" << "\n";
        cout << "nothing in path" << endl;
        // cout << "===" << "\n";
    }
}

/*
 * Purpose: Add a new show to the shows linked list
 *   between the previous and the show that follows it in the list.
 * @param previousShow the show that comes before the new show
 * @param showName name of the new Show
 * @return none
 */
void ShowsList::addShow(Show* previousShow, string showName) {
    // TODO
    Show* newNode = new Show{showName, 0, 0, NULL};
    newNode -> next = nullptr;
    newNode -> name = showName;

    if (head == nullptr) {
        head = newNode;
        cout<< "adding: " << showName << " (HEAD)" << endl;
    }
    else if (previousShow == nullptr) {
        newNode -> next = head;
        head = newNode;
        cout<< "adding: " << showName << " (HEAD)" << endl;
    }
    else {
        newNode -> next = previousShow -> next;
        previousShow -> next = newNode;
        cout << "adding: " << showName << " (prev: " << previousShow->name << ")" << endl;
        
    }
}

/*
 * Purpose: populates the ShowsList with the predetermined shows
 * @param none
 * @return none
 */
void ShowsList::buildShowsList() {
    // TODO
    if(isEmpty() == false) {
        head = NULL;
    }
    addShow(NULL, "Friends");
    addShow(searchShow("Friends"), "Ozark");
    addShow(searchShow("Ozark"), "Stranger Things");
    addShow(searchShow("Stranger Things"), "The Boys");
    addShow (searchShow("The Boys"), "Better Call Saul");
}

/*
 * Purpose: Search the ShowsList for the specified show and return a pointer to that node
 * @param showName - name of the show to look for in list
 * @return pointer to node of show, or NULL if not found
 *
 */
Show* ShowsList::searchShow(string showName) {
    // TODO
    Show* str = head;
    while(str != nullptr) {
        if(str -> name == showName) {
            return str;
        }
        str = str -> next;
    } 

    return nullptr;
}

/*
 * Purpose: Give a new rating to a show
 * @param receiver - name of the show that is receiving the rating
 * @param rating - the rating that is being given to a show
 * @return none
 */
void ShowsList::addRating(string receiver, double rating) {
    // TODO
    
    Show* node = searchShow(receiver);

    if (isEmpty()) {
        cout << "Empty list" << "\n";
        
    }
    else if (node == NULL) {
        cout << "Show not found" << "\n";
    }
    else {
        node -> numberRatings++;
        node -> rating = (node -> rating * (node->numberRatings - 1) + rating) / node -> numberRatings;
        cout << "The rating has been updated: " << node->rating << endl;
    }

}
