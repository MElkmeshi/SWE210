#pragma once

/*-- LLQueue.h -------------------------------------------------------------

 This header file defines a Queue data type.
 Basic operations:
 constructor:  Constructs an empty queue
 empty:        Checks if a queue is empty
 enqueue:      Modifies a queue by adding a value at the back
 front:        Accesses the top queue value; leaves queue unchanged
 dequeue:      Modifies queue by removing the value at the front
 display:      Displays all the queue elements
 Note: Execution terminates if memory isn't available for a queue element.
 ---------------------------------------------------------------------------*/

#include <iostream>
using namespace std;


template<class QueueElement>

class LLQueue
{
public:
	/***** Function Members *****/
	/***** Constructors *****/

	LLQueue();
	/*-----------------------------------------------------------------------
	 Construct a Queue object.

	 Precondition:  None.
	 Postcondition: An empty Queue object has been constructed.
	 (myFront and myBack are initialized to null pointers).
	 -----------------------------------------------------------------------*/

	LLQueue(const LLQueue& original);
	/*-----------------------------------------------------------------------
	 Copy Constructor

	 Precondition:  original is the queue to be copied and is received
	 as a const reference parameter.
	 Postcondition: A copy of original has been constructed.
	 -----------------------------------------------------------------------*/

	 /***** Destructor *****/
	~LLQueue();
	/*-----------------------------------------------------------------------
	 Class destructor

	 Precondition:  None.
	 Postcondition: The linked list in the queue has been deallocated.
	 -----------------------------------------------------------------------*/

	 /***** Assignment *****/
	const LLQueue& operator= (const LLQueue& rightHandSide);
	/*-----------------------------------------------------------------------
	 Assignment Operator

	 Precondition:  rightHandSide is the queue to be assigned and is
	 received as a const reference parameter.
	 Postcondition: The current queue becomes a copy of rightHandSide
	 and a reference to it is returned.
	 -----------------------------------------------------------------------*/

	bool empty() const;
	/*-----------------------------------------------------------------------
	 Check if queue is empty.

	 Precondition:  None.
	 Postcondition: Returns true if queue is empty and false otherwise.
	 -----------------------------------------------------------------------*/

	void enqueue(const QueueElement& value);
	/*-----------------------------------------------------------------------
	 Add a value to a queue.

	 Precondition:  value is to be added to this queue.
	 Postcondition: value is added at back of queue.
	 -----------------------------------------------------------------------*/

	void display(ostream& out) const;
	/*-----------------------------------------------------------------------
	 Display values stored in the queue.

	 Precondition:  ostream out is open.
	 Postcondition: Queue's contents, from front to back, have been
	 output to out.
	 -----------------------------------------------------------------------*/

	QueueElement front() const;
	/*-----------------------------------------------------------------------
	 Retrieve value at front of queue (if any).

	 Precondition:  Queue is nonempty.
	 Postcondition: Value at front of queue is returned, unless the queue
	 is empty; in that case, an error message is displayed.
	 -----------------------------------------------------------------------*/

	void dequeue();
	/*-----------------------------------------------------------------------
	 Remove value at front of queue (if any).

	 Precondition:  Queue is nonempty.
	 Postcondition: Value at front of queue has been removed, unless
	 queue is empty; in that case, an error message is displayed
	 and execution allowed to proceed.
	 -----------------------------------------------------------------------*/

private:
	/*** Node class ***/
	class Node
	{
	public:
		QueueElement data;
		Node* next;
		//--- Node constructor
		Node(QueueElement value)
			/*-------------------------------------------------------------------
			 Precondition:  value and link are received
			 Postcondition: A Node has been constructed with value in its
			 data part and its next part set to link (default 0).
			 ------------------------------------------------------------------*/
		{
			data = value; next = 0;
		}

	};

	typedef Node* NodePointer;

	/***** Data Members *****/
	NodePointer myFront,      // pointer to front of queue
		myBack;       // pointer to back of queue

}; // end of class declaration





//cpp
template<class QueueElement>
LLQueue<QueueElement>::LLQueue() :myBack(0), myFront(0)
{
}
template<class QueueElement>
LLQueue<QueueElement>::LLQueue(const LLQueue& original)
{
	if (original.empty()) { return; }
	this->myFront = new Node(original.myFront->data);
	Node* frontPtr = this->myFront;
	for (Node* i = original.myFront->next; i != NULL; i = i->next)
	{
		Node* ptr = new Node(i->data);
		frontPtr->next = ptr;
		frontPtr = frontPtr->next;
	}
	this->myBack = frontPtr;
}
template<class QueueElement>
LLQueue<QueueElement>::~LLQueue()
{
	for (Node* i = myFront; i != NULL; i = myFront) {
		myFront = myFront->next;
		delete i;
	}
}
template<class QueueElement>
const LLQueue<QueueElement>& LLQueue<QueueElement>::operator=(const LLQueue<QueueElement>& rightHandSide)
{
	if (this != &rightHandSide)
	{
		if (rightHandSide.empty()) { return *this; }
		this->~LLQueue();
		this->myFront = new Node(rightHandSide.myFront->data);
		Node* frontPtr = this->myFront;
		for (Node* i = rightHandSide.myFront->next; i != NULL; i = i->next)
		{
			Node* ptr = new Node(i->data);
			frontPtr->next = ptr;
			frontPtr = frontPtr->next;
		}
		this->myBack = frontPtr;
	}
	return *this;
}
template<class QueueElement>
bool LLQueue<QueueElement>::empty() const
{
	return myFront == NULL;
}
template<class QueueElement>
void LLQueue<QueueElement>::enqueue(const QueueElement& value)
{
	Node* ptr = new Node(value);
	if (myFront == NULL) {
		myBack = myFront = ptr;
	}
	else
	{
		myBack->next = ptr;
		myBack = ptr;
	}
}
template<class QueueElement>
void LLQueue<QueueElement>::display(ostream& out) const
{
	for (Node* i = myFront; i != NULL; i = i->next)
		out << i->data << " ";
	out << endl;
}
template<class QueueElement>
QueueElement LLQueue<QueueElement>::front() const
{
	return myFront->data;
}
template<class QueueElement>
void LLQueue<QueueElement>::dequeue()
{
	if (myFront == NULL)
		return;
	else
		myFront = myFront->next;
}
