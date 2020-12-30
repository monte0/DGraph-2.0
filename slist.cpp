#include <iostream>
#include "slist.h"

using namespace std;

slist::slist()
{
	//cout << " in slist constructor. " << endl;
}
//Purpose: The client enters a number they want found, then the function returns the position that number is at
//Parameter:The number the client wants found in the linked list
int slist::search(el_t Key)
{
	int pos = 0;				//pos will hold the number the key is at
	int c = 1;					//c is the current place of the Node
	Node* tmp;					//tmp is a Node 
	tmp = Front;				//tmp points at Front
	while (tmp != NULL)			//check if tmp points at NULL
	{
		if (tmp->Elem == Key)	//check if the element of the Node is equal to the key
			pos = c;			//assign pos with the value that is in c
		tmp = tmp->Next;		//tmp is now thte next node
		c++;					//increment c
	}
	if (pos >= 1)				//check if pos is 1 or greater
		return pos;				//then return the pos
	else
		return 0;				//else return 0
}

//Purpose: Replace a element of a certain Node with a value eneterd by client
//Parameter: THe new value that will be assigned and the position of where to put it
void slist::replace(el_t elm, int I)
{
	Node* tmp;				//tmp Node that will move through the linked list
	tmp = Front;			//tmp points at Front
	if (I > Count || I < 1)	//check if the position to check id out of range
		throw OutOfRange();	//throw exception
	for (int k = 1; k < I; k++)		//move through the linked list until you get to the Node the user wants
	{
		tmp = tmp->Next;			//move to the next node
	}
	tmp->Elem = elm;				//once at the position, make elem the number the client entered.
}

//Purpose: Checks if the two list have the same values
//Parameter: One slist object to compare to
bool slist::operator==(const slist& list2)
{
	Node* tmp1;				//a tmp Node that will iterate through one slist list
	Node* tmp2;				//a second tmp Node that will iterate through the slist object that the client passed by reference
	tmp1 = this->Front;		//point to the Front of current slist object
	tmp2 = list2.Front;		//point to the Front of the parameter object
	if (this->Count == 0 && list2.Count == 0)		//check if the objects are empty	
		return true;								//then return true
	else if (this->Count != list2.Count)	//check if the two objects have the same number of elements
		return false;						//then return false, if they dont have the same number of elements
	else
	{
		//here the two objects have the same number of elements
		while (tmp1 != NULL)				//check tmp1 points to NULL 
		{
			if (tmp1->Elem != tmp2->Elem)	//check if the two elements are equal or not
			{
				return false;				//if two elements are not equal then return false
			}
			else
			{
				//here two numbers are equal
				tmp1 = tmp1->Next;			//increment to point to next Node
				tmp2 = tmp2->Next;			//increment to point to next Node
			}
		}
		//here all elemts are equal to each other
		return true;				//return true
	}
}