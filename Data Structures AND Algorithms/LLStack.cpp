#include "LLStack.h"

LLStack::LLStack():myTop(0)
{
}

LLStack::LLStack(const LLStack& original)
{
	if (original.myTop == NULL) { return; };
	this->myTop = new Node(original.myTop->data);
	Node* thisptr = this->myTop;
	for (Node* i = original.myTop->next; i != NULL; i = i->next)
	{
		Node* ptr = new Node(i->data);
		thisptr->next = ptr;
		thisptr = thisptr->next;
	}
}

LLStack::~LLStack()
{
	for (Node* i=myTop;i!=0;i=myTop)
	{
		myTop = myTop->next;
		delete i;
	}
}

const LLStack& LLStack::operator=(const LLStack& rightHandSide)
{
	if (this != &rightHandSide)
	{
		this->~LLStack();
		if (rightHandSide.myTop == NULL) { return *this; };
		this->myTop = new Node(rightHandSide.myTop->data);
		Node* thisptr = this->myTop;
		for (Node* i = rightHandSide.myTop->next; i != NULL; i = i->next)
		{
			Node* ptr = new Node(i->data);
			thisptr->next = ptr;
			thisptr = thisptr->next;
		}
	}
	return *this;
}

bool LLStack::empty() const
{
	return myTop==NULL;
}

void LLStack::push(const StackElement& value)
{
	Node* ptr = new Node(value);
	ptr->next = myTop;
	myTop = ptr;
}

void LLStack::display(ostream& out) const
{
	for (Node* i = myTop; i != 0; i = i->next)	{
		out << i->data << " ";
	}
	out << endl;
}

StackElement LLStack::top() const
{
	return myTop->data;
}

void LLStack::pop()
{
	myTop = myTop->next;
}
