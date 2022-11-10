#include "DynamicList.h"

DynamicList::DynamicList(int maxSize):mySize(0),myCapacity(maxSize)
{
	this->myArray = new ElementType[this->myCapacity];
}

DynamicList::~DynamicList()
{
	delete myArray;
}

DynamicList::DynamicList(const DynamicList& origList):mySize(origList.mySize),myCapacity(origList.myCapacity)
{
	this->myArray = new ElementType[this->myCapacity];
	for (int i = 0; i < origList.mySize; i++)
		this->myArray[i] = origList.myArray[i];

}

const DynamicList& DynamicList::operator=(const DynamicList& rightHandSide)
{
	if (this != &rightHandSide)
	{
		if (this->myCapacity != rightHandSide.myCapacity)
		{
			this->~DynamicList();
			this->myArray = new ElementType[rightHandSide.myCapacity];
		}
		for (int i = 0; i < rightHandSide.mySize; i++)
			this->myArray[i] = rightHandSide.myArray[i];
	}
	return *this;
}

DynamicList DynamicList::operator+(const DynamicList& aList1)
{
	DynamicList tmpList;
	for (int i = 0; i < aList1.mySize; i++)
		tmpList.myArray[i] = aList1.myArray[i];
	for (int i = 0; i < this->mySize; i++)
		tmpList.myArray[i + aList1.mySize] = this->myArray[i];
	tmpList.mySize = this->mySize + aList1.mySize;
	return tmpList;
}

bool DynamicList::empty() const
{
	return this->mySize == 0;
}

void DynamicList::insert(ElementType item, int pos)
{
	this->myArray[pos] = item; this->mySize++;
}

void DynamicList::erase(int pos)
{
	mySize--;
	for (int i = pos; i < this->mySize; i++)
	{
		this->myArray[i] = this->myArray[i + 1];
	}
}

void DynamicList::display(ostream& out) const
{
	for (int i = 0; i < this->mySize; i++)
	{
		out << this->myArray[i] << " ";
	}
	cout << endl;
}
