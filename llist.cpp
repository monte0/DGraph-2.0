#include<iostream>
#include"llist.h" 

using namespace std;

llist::llist()
{
	//cout << "calling the llist constructor " << endl;
	this->Front = NULL;
	this->Rear = NULL;
	Count = 0;
}

llist::~llist()
{
	el_t x;
	//cout << "calling the llist destructor " << endl;
	while (isEmpty() != true)
		deleteFront(x);
}

//PURPOSE: Returns true if the llist is empty, empty means Front and Rear pointing to NULL and Count being 0
//PARAMETER: None
bool llist::isEmpty()
{
	if (this->Front == NULL && this->Rear == NULL && Count == 0)
		return true;
	else
		return false;
}

//PURPOSE: Displas every element of a llist using a while loop. Stops when P points to NULL.
//PARAMETER: None
void llist::displayAll()
{
	if (isEmpty() == true)
		cout << "[ empty ]" << endl;
	else
	{
		Node* c;							//new Node to keep track of next
		c = Front;							//c starts at the front
		cout << "[ ";
		while (c != NULL)					//checks to see if P points to NULL
		{									//if it doesnt keep looping
			cout << c->Elem << " ";			//display the element of current c
			c = c->Next;					//assign next c
		}
		cout << "] " << endl;
	}
}

//PURPOSE: Takes in a new element and adds that to the end of the llist.
//PARAMETER: One element to add
void llist::addRear(el_t NewNum)
{
	//special case
	if (isEmpty() == true)			//checks to see if the llist is empty 
	{
		Node* P = new Node;			//if it is empty then create a Node
		Front = P;					//Front/Rear both point to new Node P
		Rear = P;
		P->Elem = NewNum;			//the element of P is now the NewNum
		Rear->Next = NULL;
		Count++;					//increment the element counter
	}
	else //if llist is not empty then go here, regular case
	{
		Rear->Next = new Node;		//make new node to hold element and rear
		Rear = Rear->Next;			//Rear is now points to next node
		Rear->Elem = NewNum;		//assign rear element the NewNum
		Rear->Next = NULL;			//have the rear->next  point to NULL
		Count++;					//increment the counter to update llist
	}
}

//PURPOSE: adds a new element to the beginning of the llist
//PARAMETER: Element by the user is only parameter
void llist::addFront(el_t NewNum)
{
	//special case
	if (isEmpty() == true)			//checks to see if the llist is empty 
	{
		Node* P = new Node;			//if it is empty then create a Node
		Front = P;					//Front/Rear both point to new Node P
		Rear = P;
		Rear->Next = NULL;
		P->Elem = NewNum;			//the element of P is now the NewNum
		Count++;					//increment the element counter
	}
	else //if llist is not empty go here, regular case
	{
		Node* x = new Node;			//create new Node
		x->Elem = NewNum;				//X's element is now NewNum
		x->Next = Front;				//Make x point to Front first
		Front = x;					//then make Front point to X
		Count++;					//update Counter

	}
}

//PURPOSE: Deletes the Front Node and reassigns the Front pointer to the new Front
//PARAMETER:one parameter called OldNum that is assigned to the element that gets deleted
void llist::deleteFront(el_t& OldNum)
{
	//error case
	if (isEmpty() == true)				//check to see if llist is emppty
	{
		throw Underflow();				//if it is then throw an exception, since you cant delete front if there is no front
	}
	//special case
	else if (Count == 1)				//checks to see if count is 1
	{
		OldNum = Front->Elem;			//if it is then assign the element about to be deleted to OldNum
		delete Front;					//delete the Front
		Front = NULL;					//have both Front and Rear point to NULL
		Rear = NULL;
		Count--;						//decrement counter by one
	}
	//regular case
	else
	{
		OldNum = Front->Elem;			//assign Front elem to OldNum before it gets deleted
		Node* Second;					//make a new Node named Second
		Second = Front->Next;			//have Second point to Front next
		delete Front;
		Front = Second;					//Make Front point to Second
		Count--;						//decrement counter
	}
}

//PURPOSE: Deletes the LAst Node and reassigns the Rear pointer to the new Last Node
//PARAMETER:one parameter called OldNum that is assigned to the front element
void llist::deleteRear(el_t& OldNum)
{
	//error case
	if (isEmpty() == true)				//check to see if llist is emppty
	{
		throw Underflow();				//if it is then throw an exception, since you cant delete front if there is no front
	}
	//special case
	else if (Count == 1)				//checks to see if count is 1
	{
		OldNum = Rear->Elem;			//if it is then assign the element about to be deleted to OldNum
		delete Rear;					//delete the Front
		Front = NULL;					//have both Front and Rear point to NULL
		Rear = NULL;
		Count--;						//decrement counter by one
	}
	//regular case
	else
	{
		OldNum = Rear->Elem;			//assign Rear elem to OldNum before it gets deleted
		Node* P;						//make a new Node named P
		P = Front;						//have P point to Front
		while (P->Next->Next != NULL)	//make it loop until it gets to the second-to-last Node that equals NULL
			P = P->Next;				//assign P to P->next to move linearly through the llist
		P->Next = NULL;					//when you get to the second to last Node, make P->next point to NULL
		delete Rear;					//delete Rear
		Rear = P;						//Make Rear point to P
		Count--;						//decrement counter
	}
}

//PURPOSE: Deletes the ith Node in the llist
//PARAMETER: The ith Node the user wants, and gets the element about to be deleted and stores it to OldNum
void llist::deleteIth(int I, el_t& OldNum)
{
	if (I > Count)					//error case, checks to see if I is bigger than the count
		throw OutOfRange();			//throw xception
	else if (I < 1)					//error case, checks to see if the I is less than 1
		throw Underflow();			//throw exception
	else if (I == 1)				//special case, checks to see if the the I is the first Node so deleteFron can be called
	{
		deleteFront(OldNum);
	}
	else if (I == Count)			//special case, checks to see if the I is the last Node, so deleteRear can be called
	{
		deleteRear(OldNum);
	}
	else
	{
		Node* P;
		Node* Q;
		P = Front;						//make P set to Front, so it can loop to the I - 1th Node.
		for (int K = 0; K < I - 2; K++)  // for I-2 times, so I arrive at the Node before the one that gets deleted
		{
			P = P->Next;
		}
		// now you are at the I - 1th node
		Q = P->Next;				//Q points at the Node about to be deleted
		P->Next = Q->Next;			//P points at the Node ahead of Q
		OldNum = Q->Elem;			//assign OldNum the elem about to be deleted
		delete Q;					//delete the Ith NOde
		Count--;					//decrement for the Node deleted
	}

}

//PURPOSE: User inserts a Node at a specific place and gives the function the element.
//PARAMETER:Two Parameters, I the place where a new node will be inserted, and newNum the element of the new Node
void llist::insertIth(int I, el_t newNum)
{
	if (I < 1)								//error case, check if the I is below 1		
		throw Underflow();					//then throw exception
	else if (I > Count + 1)					//error case, check if I is greater than the count of Nodes
		throw OutOfRange();					//then throw exception
	else if (I == 1)						//special case, checks if user wants to insert at the Front
	{
		addFront(newNum);					//then call addFront 
	}
	else if (I == Count + 1)				//special case, check if user wqants to insert at the Rear
	{
		addRear(newNum);					//then call addRear
	}
	else
	{
		Node* P;
		Node* Q;
		P = Front;						//P will iterate through the llist to arrive at the I - 1th Node
		for (int K = 1; K <= I - 2; K++)  // for I-2 times, so I arrive at the Node before the one that gets inserted
		{
			P = P->Next;
		}
		// now you are at the I - 1th node
		Q = P->Next;				//Q points at the Node thats gonna be moved ahead
		P->Next = new Node;			//P->next makes room for the newly inserted Node
		P = P->Next;				//P points at the inserted Node
		P->Elem = newNum;			//P's elem is the one the user passed in
		P->Next = Q;				//connect P to the next Node
		Count++;					//increment for the new Node
	}
}

//PURPOSE:
//PARAMETER:
llist::llist(const llist& Original)
{
	//this->'s data members need to be initialized here first
	Front = NULL;
	Rear = NULL;
	Count = 0;
	//  this-> object has to be built up by allocating new cells
	//  and copying the values from Original into each cell as we did with 
	//  operator= above. To do this,
	//copy here the(**) lines in Operator Overloading of = but note that it is Original and not OtherOne.
	Node* P;  // local pointer for Original
	P = Original.Front;
	while (P != NULL)  // a loop which repeats until you reach the end of Original. 
	{
		this->addRear(P->Elem);    //P’s element is added to this->
		P = P->Next;                         // Go to the next node in Original   
	}
	//  Nothing to return because this is a constructor.
}

//PURPOSE:
//PARAMETER:
llist& llist::operator=(const llist& OtherOne)
{
	el_t tmp;
	if (&OtherOne != this)
	{
		while (!this->isEmpty())
			this->deleteRear(tmp);
		Node* P;  // local pointer for OtherOne
		P = OtherOne.Front;
		while (P != NULL)  // a loop which repeats until you reach the end of OtherOne. 
		{
			this->addRear(P->Elem);    //P’s element is added to this->
			P = P->Next;                         // Go to the next node in OtherOne   
		}
	}// end of if              
	return *this;
}