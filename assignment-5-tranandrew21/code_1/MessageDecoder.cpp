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
}

bool MessageDecoder::isEmpty()
{
	/* finished. do not touch. */
    return (head == NULL);
}

void MessageDecoder::push(char ch)
{
	// TODO
}

void MessageDecoder::pop()
{   
	// TODO
}

Parser* MessageDecoder::peek()
{
	// TODO
	return nullptr;
}

void MessageDecoder::evaluate(char str[])
{
	// TODO
}
