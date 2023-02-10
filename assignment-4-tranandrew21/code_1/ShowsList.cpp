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
    // TODO: Copy-paste your solution from Assignment 3
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
    // TODO: Copy-paste your solution from Assignment 3
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
    // TODO: Copy-paste your solution from Assignment 3
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
    // TODO: Copy-paste your solution from Assignment 3
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
    // TODO: Copy-paste your solution from Assignment 3
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


/****************************************************/
/*  ASSIGNMENT 4: Functions to be completed below.  */
/****************************************************/


/*
 * Purpose: Delete the Show in the list with the specified name.
 * @param showName - name of the Show to delete in the list.
 * @return none
 */
void ShowsList::removeShows(string showName)
{
    //TODO: Complete this function
    Show* search = searchShow(showName);
    if (search == NULL) {
        cout << "Show does not exist." << endl;
        return;
    }
    if(head -> name == showName) {
        Show* temp = head;
        head = head -> next;
        delete temp;
    }
    else {
        Show* prev = head;
        Show* temp = prev -> next;
        bool isFound = false;
        while (temp != NULL && isFound != true) {
            if (temp -> name == showName) {
                prev -> next = temp -> next;
                delete temp;
                isFound = true;
            }
            else {
                prev = temp;
                temp = temp -> next;
            }
        }


    }
}

/*
 * Purpose: deletes all Shows in the list starting from the head of the linked list.

 * @param: none
 * @return: none
 */
void ShowsList::purgeCompleteShowList()
{
    // TODO: Complete this function
    Show* temp = head;
    
    if (isEmpty()) {
        return;
    }
    else {
        while (temp != NULL) {
            Show* next = temp -> next;
            cout << "deleting: " << temp -> name << endl;
            delete temp;
            temp = next;
        }
        head = NULL;
        cout << "Deleted show list" << endl;
    }
}

/*
* Purpose: Creates a loop from last node to the show name specified.
* @param showName - name of the show to loop back to
* returns the last node before loop creation (to break the loop)
*/
Show* ShowsList::produceGlitch(string showName) 
{
    /*
    DO NOT MODIFY THIS
    This function is already complete. 
    */
    Show* ptr = searchShow(showName);
    Show* temp = head;
    while(temp && temp->next!=NULL){
        temp=temp->next;
    }
    if(ptr && temp)
        temp->next=ptr;
    return temp;
}

/*
 * Purpose: to detect loop in the linked list
 * @return: true if loop is detected, else false
 */
bool ShowsList::findGlitch() 
{
    // TODO: Complete this function
    Show *slower = head, *faster = head;
    while(slower && faster -> next && faster) {
        slower = slower -> next;
        faster = faster -> next -> next;
        if(slower == faster) return true;
    }
    return false;
}

void ShowsList::rearrangeShowList(int start, int end)
{
    // TODO: Complete this function
    if(head == NULL) {
        cout << "Linked List is Empty.";
        return;
    }
    Show* curr = head;
    int len = 0;

    while (curr != NULL) {
        len++;
        curr = curr -> next;
    }
    if (end < 0 || end >= len - 1) {
        cout << "Invalid end index" << endl;
        return;
    }
    if (start < 0 || start > len) {
        cout << "Invalid start index" << endl;
        return;
    }
    if (start > end) {
        cout << "Invalid indices" << endl;
    }

    int show = 0;
    Show* current = head;
    Show* prev = NULL;
    Show* l;
    Show* p;
    Show* c;
    Show* temp;
    while(current != NULL) {
        if(show == start) {
            p = prev;
            c = current;
        }
        if(show == end) {
            l = current;
        }
        prev = current;
        current = current -> next;
        show++;
    }
    prev -> next = c;
    temp = l -> next;
    l -> next = NULL;
    if(start == 0) {
        head = temp;
    }
    else {
        p -> next = temp;
    }
}
