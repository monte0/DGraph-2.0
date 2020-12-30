#include <iostream>
#include "dgraph.h"
#include "stack.h"
#include "slist.h"

using namespace std;

int main()
{
	stack myS;			//will hold vertexs
	el_t x;				//holds the char letter that is poped from stack
	int i = 1;			//visit number starts at one and will be incremented throughout  while loop
	slist myll;			//will hold the adjacencyones from drgraph
	dgraph myG;
	myG.fillTable();	//fills table with same table.txt file from HW9
	myG.displayGraph();							//Display the graph before DFS begins.

	myS.push('A');								//Push A onto the stack to start.

	while (myS.isEmpty() != true)								//While the stack is not empty do:
	{
		myS.pop(x);												//Remove a vertex v from the stack.
		cout << "Removed " << x << " from stack" << endl;		//Display the vertex name.E.G.“Removed B from stack”
		if (myG.isMarked(x) != true)							//If v is not marked yet(visit number is 0) then
		{
			myG.visit(i, x);									//•	mark it(visit it **) 
			cout << "Visit " << x << " as " << i << endl;		//and inform the user E.G.“Visit B as 2”

			myll = myG.findAdjacency(x);						//•	get its adjacency list
			if (myll.isEmpty() == true)//o if no adjacent ones inform the user E.G.“Deadend reached – go one vertex up to take another path.”
			{
				cout << "Dead end reached - go one vertex up to take another path." << endl;
			}
			else//put adjacent ones on stack
			{
				cout << "...pushing ";
				myll.displayAll();
				while (myll.isEmpty() != true)
				{
					myll.deleteRear(x);			//delete from the rear of adjacency list and push them 
					myS.push(x);
				}
			}
			cout << "stack is: " << endl;	//displays current stack
			myS.displayAll();
			i++;
		}
		else//else inform the user E.G.“B had been visited already - go one vertex up to take another path.”
		{
			cout << x << " had been visited already - go one vertex up to take another \npath. Stack is " << endl;
			myS.displayAll();		//Display the stack clearly labeling it as the current stack
		}
	}//while loop ends here
	myG.displayGraph();		//Display the Graph nicely with visit numbers for all vertices. 
}