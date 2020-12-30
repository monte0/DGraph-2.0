using namespace std;
#include <iostream>
#include "stack.h"

//PURPOSE:  Constructor must initialize top to be -1 to begin with.
stack::stack()
{
	top = -1; // indicate an empty stack }
}

//PURPOSE:  Destructor does not have to do anything since this is a static array.
stack::~stack()
{
	if (isEmpty() != true)
	{
		clearIt();
	}
}

//PURPOSE:  checks top and returns true if empty (if top = -1), false otherwise.
bool stack::isEmpty()
{
	if (top == -1)
		return true;
	else
		return false;
}

//PURPOSE: checks top and returns true if full (if top = MAX -1), false otherwise.
bool stack::isFull()
{
	if (top == MAX - 1)
		return true;
	else
		return false;
}

//PURPOSE: calls isFull and if true, throws an exception (Overflow)
//   Otherwise, adds an element to el after incrementing top.
//PARAMETER: pass the element (elem) to be pushed 
void stack::push(el_t elem)
{
	if (isFull() == true)
		throw Overflow();
	else
	{
		top++;
		el[top] = elem;
	}
}

//PURPOSE: calls isEmpty and if true, throws an exception (Underflow)
//  Otherwise, removes an element from el and gives it back.
//PARAMETER: provide a holder (elem) for the element popped (pass by ref)
void stack::pop(el_t& elem)
{
	if (isEmpty() == true)
		throw Underflow();
	else
	{
		elem = el[top];
		top--;
	}
}

// PURPOSE: calls isEmpty and if true, throws an exception (underflow)
//    Otherwise, gives back the top element from el.
//PARAMETER: provide a holder (elem) for the element (pass by ref)
void stack::topElem(el_t& elem)
{
	if (isEmpty() == true)
		throw Underflow();
	else
		elem = el[top];
}

//PURPOSE: dislayAll calls isEmpty and if true, displays [ empty ].
//         Otherwise, diplays the elements vertically.
void stack::displayAll()
{
	if (isEmpty() == true)
		cout << "[ empty ]" << endl;
	else
		for (int i = top; i >= 0; i--)
		{
			cout << el[i] << endl;
		}
	cout << "--------------" << endl;
}


//PURPOSE: pops all elements from the stack to make it empty if it is not empty yet.
void stack::clearIt()
{
	el_t temp;
	if (isEmpty() == true)
		throw Underflow();
	else
		while (top != -1)
		{
			pop(temp);
		}
}