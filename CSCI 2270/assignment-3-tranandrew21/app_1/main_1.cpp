#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include "../code_1/ShowsList.hpp"

using namespace std;

void displayMenu();

int main(int argc, char* argv[])
{

    // DO NOT MODIFY THIS.
    if(argc>1) 
    {
        freopen(argv[1],"r",stdin);
    }
    // DO NOT MODIFY ABOVE.

    // TODO
    int input = 0;
    

    ShowsList obj;

    while(input != 5) {
        
        displayMenu();
        cin >> input;

        if (input == 1) { // Build

            obj.buildShowsList();
            obj.displayShows();
        }
        else if (input == 2) { // Display Show
            if (obj.isEmpty() == false) {
                obj.displayShows();
            }
            else {
                obj.displayShows();
            }
        }
        else if (input == 3) { // Add show
            string showName;
            string prevShow;

            bool exists = true;

            cout << "Enter a new show name: " << endl;
            cin.ignore();
            getline(cin, showName);
            cout << "Enter the previous show name (or First): " << endl;
            getline(cin, prevShow);
            if (prevShow == "First") {
                obj.addShow(NULL, showName);
            }
            else if (obj.searchShow(prevShow) == NULL) {
                exists = false;
                // Check if previousShow exists
                while (exists == false) {
                    cout << "INVALID(previous show name)... Please enter a VALID previous show name!" << endl;
                    cin.clear();
                    getline(cin, prevShow);
                    if(prevShow == "First" || obj.searchShow(prevShow) != NULL) {
                        exists = true;
                        obj.addShow(obj.searchShow(prevShow), showName);
                    }
                }
            }
            else {
                obj.addShow(obj.searchShow(prevShow), showName);
            }
            obj.displayShows();

        }
        else if (input == 4) { // addRating
            cin.ignore();
            string showName = "";
            double rating;    

            cout << "Enter name of the show to add the rating: " << endl;
            getline(cin, showName);
            cout << "Enter the rating: " << endl;
            cin >> rating;

            obj.addRating(showName, rating);

        }
    }
    if(input == 5) {
        cout << "Quitting..." << endl;
    }
    cout << "Goodbye!" << endl;
}




/************************************************
           Definitions for main_1.cpp
************************************************/
void displayMenu()
{

    // COMPLETE
    cout << "Select a numerical option:" << endl;
    cout << "+=====Main Menu=========+" << endl;
    cout << " 1. Build schedule " << endl;
    cout << " 2. Display Shows " << endl;
    cout << " 3. Add Show " << endl;
    cout << " 4. Add rating" << endl;
    cout << " 5. Quit " << endl;
    cout << "+-----------------------+" << endl;
    cout << "#> ";
}
