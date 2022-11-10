#include "StaticList.h"

StaticList::StaticList():mySize(0)
{
}

bool StaticList::empty() const
{
	return this->mySize==0;
}

void StaticList::insert(ElementType item, int pos)
{
	this->myArray[pos] = item; this->mySize++;
}

void StaticList::erase(int pos)
{
	mySize--;
	for (int i = pos; i < this->mySize; i++)
	{
		this->myArray[i] = this->myArray[i + 1];
	}
}

void StaticList::display(ostream& out) const
{
	for (int i = 0; i < this->mySize; i++)
	{
		out << this->myArray[i] << " ";
	}
	cout << endl;
}

ostream& operator<<(ostream& out, const StaticList& aList)
{
	aList.display(out);
	return out;
}
