#include "../code_2/EnqueueDequeue.hpp"
#include <iostream>

using namespace std;

/*
 * Purpose: displays a menu with options
 * @param none
 * @return none
 */
void menu(){
	cout << "*----------------------------------------*" << endl;
	cout << "Choose an option:" << endl;
    cout << "1. Enqueue new shows (Add shows to the queue)" << endl;
	cout << "2. Dequeue (Retrieve shows from the queue)" << endl;
	cout << "3. Return the queue size and exit" << endl;
	cout << "*----------------------------------------*" << endl;
}

int main(int argc, char const *argv[])
{
    // DO NOT MODIFY THIS.
    if(argc > 0)
    {
        freopen(argv[1],"r",stdin);
    }
    
    /* TODO */
    
    return 0;
}