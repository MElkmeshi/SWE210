#pragma once
//
//  DList.hpp
//  DynamicList
//
//  Created by Ashraf AbdelRaouf on 9/22/15.
//  Copyright 2015 Ashraf AbdelRaouf. All rights reserved.
//
/*-- DList.h --------------------------------------------------------------

 This header file defines the data type List for processing lists.
 Basic operations are:
 Constructor
 Destructor
 Copy constructor
 Assignment operator
 empty:    Check if list is empty
 insert:   Insert an item
 erase:    Remove an item
 display:  Output the list
 << :      Output operator
 -------------------------------------------------------------------------*/

#include <iostream>
using namespace std;

typedef int ElementType;
class DynamicList
{
public:
    /******** Function Members ********/
    /***** Class constructor *****/
    DynamicList(int maxSize = 1024);
    /*----------------------------------------------------------------------
     Construct a List object.

     Precondition:  maxSize is a positive integer with default value 1024.
     Postcondition: An empty List object is constructed; myCapacity ==
     maxSize (default value 1024); myArray points to a dynamic
     array with myCapacity as its capacity; and mySize is 0.
     -----------------------------------------------------------------------*/

     /***** Class destructor *****/
    ~DynamicList();
    /*----------------------------------------------------------------------
     Destroys a List object.

     Precondition:  The life of a List object is over.
     Postcondition: The memory dynamically allocated by the constructor
     for the array pointed to by myArray has been returned to the heap.
     -----------------------------------------------------------------------*/

     /***** Copy constructor *****/
    DynamicList(const DynamicList& origList);
    /*----------------------------------------------------------------------
     Construct a copy of a List object.

     Precondition:  A copy of origList is needed; origList is a const
     reference parameter.
     Postcondition: A copy of origList has been constructed.
     -----------------------------------------------------------------------*/

     /***** Assignment operator *****/
    const DynamicList& operator=(const DynamicList& rightHandSide);
    /*----------------------------------------------------------------------
     Assign a copy of a List object to the current object.

     Precondition: none
     Postcondition: A copy of rightHandSide has been assigned to this
     object. A const reference to this list is returned.
     -----------------------------------------------------------------------*/

     /***** Plus operator *****/
    DynamicList operator+ (const DynamicList& aList1);
    /*----------------------------------------------------------------------
     Add elements of two lists.

     Precondition:  two objects of type lists are added using + operator.
     Postcondition: The list represented by this List object has been
     inserted into out.
     -----------------------------------------------------------------------*/

     /***** empty operation *****/
    bool empty() const;
    /*----------------------------------------------------------------------
    Check if a list is empty.

    Precondition:  None
    Postcondition: true is returned if the list is empty, false if not.
    -----------------------------------------------------------------------*/

    /***** insert and erase *****/
    void insert(ElementType item, int pos);
    /*----------------------------------------------------------------------
     Insert a value into the list at a given position.

     Precondition:  item is the value to be inserted; there is room in
     the array (mySize < CAPACITY); and the position satisfies
     0 <= pos <= mySize.
     Postcondition: item has been inserted into the list at the position
     determined by pos (provided there is room and pos is a legal
     position).
     -----------------------------------------------------------------------*/

    void erase(int pos);
    /*----------------------------------------------------------------------
     Remove a value from the list at a given position.

     Precondition:  The list is not empty and the position satisfies
     0 <= pos < mySize.
     Postcondition: element at the position determined by pos has been
     removed (provided pos is a legal position).
     ----------------------------------------------------------------------*/

     /***** output *****/
    void display(ostream& out) const;
    /*----------------------------------------------------------------------
     Display a list.

     Precondition:  The ostream out is open.
     Postcondition: The list represented by this List object has been
     inserted into out.
     -----------------------------------------------------------------------*/

private:
    /******** Data Members ********/
    int mySize;                // current size of list
    int myCapacity;            // capacity of array
    ElementType* myArray;     // pointer to dynamic array

}; //--- end of List class

//------ Prototype of output operator
ostream& operator<< (ostream& out, const DynamicList& aList);




