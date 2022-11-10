#include "LinkedList.h"

LinkedList::LinkedList():mySize(0),first(0)
{
}

LinkedList::LinkedList(const LinkedList& origList):mySize(origList.mySize)
{
	if (origList.mySize == 0) { return; };
	 this->first = new Node(origList.first->data);
	 Node* fir = first;
	for (Node* i = origList.first->next; i != NULL; i = i->next) {
		Node* ptr = new Node(i->data);
		fir->next = ptr;
		fir = fir->next;
	}
}

LinkedList::~LinkedList()
{
	for (Node* i = first; i!= NULL; i = first) {
		first = first->next;
		delete i;
	}
}

const LinkedList& LinkedList::operator=(const LinkedList& rightSide)
{
	if (this != &rightSide)
	{
		this->~LinkedList();
		if (rightSide.mySize == 0) { return *this; };
		mySize = rightSide.mySize;
		Node* fir = new Node(rightSide.first->data);
		this->first = fir;
		for (Node* i = rightSide.first->next; i != NULL; i = i->next) {
			Node* ptr = new Node(i->data);
			fir->next = ptr;
			fir = fir->next;
		}
	}
	return *this;
}

bool LinkedList::empty()
{
	return first==NULL;
}

void LinkedList::insert(ElementType dataVal, int index)
{
	Node* ptr = new Node(dataVal);
	if (index == 0)
	{
		first = ptr;
	}
	else
	{
		Node* fir = first;
		for (int i = 0; i < index - 1; i++)
			fir = fir->next;
		fir->next = ptr;
	}
	mySize++;
}

void LinkedList::erase(int index)
{
	Node* ptr = first;
	if (index == 0)	{
		first = first->next;
		delete ptr;
	}
	else {
		for (int i = 0; i < index-1; i++)
			ptr = ptr->next;//stop at previous 
		Node* point = ptr->next; //the current
		ptr->next = point->next;
		delete point;
	}
	mySize--;
}

void LinkedList::display(ostream& out) const
{
	for (Node* i = this->first; i != NULL; i = i->next)
		out << i->data << " ";
	out << endl;
}

int LinkedList::nodeCount()
{
	if (first == NULL)
		return 0;
	int count = 1;
	for (Node* i = this->first->next; i != NULL; i = i->next)
		count++;
	return count;
}

int LinkedList::search(ElementType dataVal)
{
	int index = 0;
	for (Node* i = this->first; i != NULL; i = i->next,index++)
		if (dataVal == i->data)
			return index;
	return -1;
}

ostream& operator<<(ostream& out, const LinkedList& aList)
{
	aList.display(out);
	return out;
}
/*
istream& operator>>(istream& in, LinkedList& aList)
{
	// TODO: insert return statement here
}
*/