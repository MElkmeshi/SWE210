#include "LLQueue.h"

LLQueue::LLQueue():myBack(0),myFront(0)
{
}

LLQueue::LLQueue(const LLQueue& original)
{
	if (original.empty()) {return;}
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

LLQueue::~LLQueue()
{
	for (Node* i = myFront; i != NULL; i= myFront)	{
		myFront = myFront->next;
		delete i;
	}
}

const LLQueue& LLQueue::operator=(const LLQueue& rightHandSide)
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

bool LLQueue::empty() const
{
	return myFront == NULL;
}

void LLQueue::enqueue(const QueueElement& value)
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

void LLQueue::display(ostream& out) const
{
	for (Node* i = myFront; i != NULL; i = i->next)
		out << i->data << " ";
	out << endl;
}

QueueElement LLQueue::front() const
{
	return myFront->data;
}

void LLQueue::dequeue()
{
	if (myFront == NULL)
		return;
	else
		myFront = myFront->next;
}
