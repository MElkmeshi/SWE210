#pragma once
//
//  List.hpp
//  LinkedList
//
//  Created by Ashraf AbdelRaouf on 9/23/15.
//  Copyright 2015 Ashraf AbdelRaouf. All rights reserved.
//

#include <iostream>
using namespace std;
template <class ElementType>

class LinkedList
{



private:

    class Node {
    public:

        //------ Node DATA MEMBERS
        ElementType data;
        Node* next;

        //------ Node OPERATIONS
        //-- Default constrctor: initializes next member to Node()
        Node()
            : next(0)
        {}

        //-- Explicit-value constructor:  initializes data member to dataValue
        //--                             and next member to 0
        Node(ElementType dataValue)
            : data(dataValue), next(0)
        {}
    }; //--- end of Node class

    typedef Node* NodePointer;


    //------ DATA MEMBERS
    NodePointer first;
    int mySize;

public:
    //------ List OPERATIONS
    LinkedList();
    /*--------------------------------------------------------------------
     Default constructor: builds an empty List object.
     Precondition:  None
     Postcondition: first is 0 and mySize is 0.
     --------------------------------------------------------------------*/
    LinkedList(const LinkedList& origList);
    /*--------------------------------------------------------------------
     Copy constructor
     Precondition:  A copy of origList is needed.
     Postcondition: A distincr copy of origList has been constructed.
     --------------------------------------------------------------------*/
    ~LinkedList();
    /*--------------------------------------------------------------------
     Destructor
     Precondition:  This list's lifetime is over.
     Postcondition: This list has been destroyed.
     --------------------------------------------------------------------*/
    const LinkedList& operator=(const LinkedList& rightSide);
    /*--------------------------------------------------------------------
     Assignment operator
     Precondition:  This list must be assigned a value.
     Postcondition: A copy of rightSide has been assigned to this list.
     --------------------------------------------------------------------*/
    bool empty();
    /*--------------------------------------------------------------------
     Check if this list is empty
     Precondition:  None.
     Postcondition: true is returned if this list is empty, false if not.
     --------------------------------------------------------------------*/
    void insert(ElementType dataVal, int index);
    void add(ElementType dataVal);
    /*--------------------------------------------------------------------
     Insert a value into a list at a given index.
     Precondition:  index is a valid list index: 0 <= index <= mySize,
     Postcondition: dataVal has been inserted into the list at position
     index, provided index is valid..
     --------------------------------------------------------------------*/
    void erase(int index);
    /*--------------------------------------------------------------------
     Remove a value from a list at a given index.
     Precondition:  index is a valid list index:  0 <= index < mySize
     Postcondition: dataVal at list position index has been removed,
     provided index is valid.
     --------------------------------------------------------------------*/

    void display(ostream& out) const;
    /*--------------------------------------------------------------------
     Display the contensts of this list.
     Precondition:  ostream out is open
     Postcondition: Elements of this list have been output to out.
     --------------------------------------------------------------------*/
    int nodeCount();
    /*--------------------------------------------------------------------
     Count the elements of this list.
     Precondition:  None
     Postcondition: Number of elements in this list is returned.
     --------------------------------------------------------------------*/
    int search(ElementType dataVal);
    /*--------------------------------------------------------------------
     Search for an data value in this list.
     Precondition:  None
     Postcondition: Index of node containing dataVal is returned
     if such a node is found, -1r if not.
     --------------------------------------------------------------------*/


}; //--- end of List class
template <class ElementType>
ostream& operator<<(ostream& out, const LinkedList<ElementType>& aList);
template <class ElementType>
istream& operator>>(istream& in, LinkedList<ElementType>& aList); //didn't know how to impelment it

//cpp
template <class ElementType>
LinkedList<ElementType>::LinkedList() :mySize(0), first(0)
{
}
template <class ElementType>
LinkedList<ElementType>::LinkedList(const LinkedList& origList) :mySize(origList.mySize)
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
template <class ElementType>
LinkedList<ElementType>::~LinkedList()
{
    for (Node* i = first; i != NULL; i = first) {
        first = first->next;
        delete i;
    }
}
template <class ElementType>
const LinkedList<ElementType>& LinkedList<ElementType>::operator=(const LinkedList& rightSide)
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
template <class ElementType>
bool LinkedList<ElementType>::empty()
{
    return first == NULL;
}
template <class ElementType>
void LinkedList<ElementType>::insert(ElementType dataVal, int index)
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
template<class ElementType>
inline void LinkedList<ElementType>::add(ElementType dataVal)
{
    this->insert(dataVal, this->mySize);
}
template <class ElementType>
void LinkedList<ElementType>::erase(int index)
{
    Node* ptr = first;
    if (index == 0) {
        first = first->next;
        delete ptr;
    }
    else {
        for (int i = 0; i < index - 1; i++)
            ptr = ptr->next;//stop at previous 
        Node* point = ptr->next; //the current
        ptr->next = point->next;
        delete point;
    }
    mySize--;
}
template <class ElementType>
void LinkedList<ElementType>::display(ostream& out) const
{
    for (Node* i = this->first; i != NULL; i = i->next)
        out << i->data << " ";
    out << endl;
}
template <class ElementType>
int LinkedList<ElementType>::nodeCount()
{
    if (first == NULL)
        return 0;
    int count = 1;
    for (Node* i = this->first->next; i != NULL; i = i->next)
        count++;
    return count;
}
template <class ElementType>
int LinkedList<ElementType>::search(ElementType dataVal)
{
    int index = 0;
    for (Node* i = this->first; i != NULL; i = i->next, index++)
        if (dataVal == i->data)
            return index;
    return -1;
}
template <class ElementType>
ostream& operator<<(ostream& out, const LinkedList<ElementType>& aList)
{
    aList.display(out);
    return out;
}
/*
template <class ElementType>
istream& operator>>(istream& in, LinkedList& aList)
{
    // TODO: insert return statement here
}
*/
