#include <iostream>
#include <cstdlib>
#include <iostream>
#include "MessageDecoder.hpp"

using namespace std;
# define SIZE 50

MessageDecoder::MessageDecoder()
{
	/*
    DO NOT MODIFY THIS
    This constructor is already complete. 
    */
	head = NULL;
}

MessageDecoder::~MessageDecoder()
{
	// TODO
	while(!isEmpty()) {
		pop();
	}
	head = NULL;
}

bool MessageDecoder::isEmpty()
{
	/* finished. do not touch. */
    return (head == NULL);
}

void MessageDecoder::push(char ch)
{
	// TODO
	Parser* ptr = new Parser;
	ptr -> ch = ch;
	ptr -> next = head;
	head = ptr;
}

void MessageDecoder::pop()
{   
	// TODO
	if(isEmpty()) {
		cout << "Stack empty, cannot pop an item." << endl;
		return;
	}
	else {
		Parser* ptr = head;
		head = ptr -> next;
		delete ptr;
	}
}

Parser* MessageDecoder::peek()
{
	// TODO
	Parser* headptr = head;
	if(isEmpty()) {
		return nullptr;
	}
	else {
		return headptr;
	}
}

void MessageDecoder::evaluate(char str[])
{
	// TODO
}
