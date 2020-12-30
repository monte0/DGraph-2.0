//----- Globally setting up the aliases ----------------
#ifndef STACK
#define STACK

const int MAX = 20;   // The MAX number of elements for the stack
					 // MAX is unknown to the client

typedef char el_t;      // the el_t type is char for now
						// el_t is unknown to the client
						//-------------------------------------------------------

class stack
{
private: // to be hidden from the client

	el_t     el[MAX];       // el is  an array of el_t's
	int      top;           // top is index to the top of stack

public:  // available to the client

	// Add exception handling classes here  
	class Overflow {};
	class Underflow {};

	// prototypes to be used by the client
	// Note that no parameter variables are given

	stack();   // constructor to create an object
	~stack();  // destructor  to destroy an object

			   // PURPOSE: if not full, enters an element at the top;
			   //          otherwise throws an exception - Overflow
			   // PARAMETER: pass the element to be pushed
	void push(el_t);

	// PURPOSE: if not empty, removes and gives back the top element;
	//          otherwise throws an exception - Underflow
	// PARAMETER: provide variable to receive the popped element (by ref)
	void pop(el_t&);

	// PURPOSE: if not empty, gives the top element without removing it;
	//          otherwise, throws an exception - Underflow
	// PARAMETER: gives back the top element from el
	void topElem(el_t&);

	// Must add good comments for each function
	// Refer to C++ "CS311 How To Comment your programs" file at Cougar Courses

	//PURPOSE: if stack is empty returns true else return false
	bool isEmpty();

	//PURPOSE: if stack is full returns true else return false
	bool isFull();

	//PURPOSE: displays stack vertically
	void displayAll();

	//PURPOSE: pops all elements in stack
	void clearIt();

};
#endif // !STACK