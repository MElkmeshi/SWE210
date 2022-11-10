//
//  List.h
//  ArrayList
//
/*-- List.h ---------------------------------------------------------------

 This header file defines the data type List for processing lists.
 Basic operations are:
 Constructor
 empty:    Check if list is empty
 insert:   Insert an item
 erase:    Remove an item
 display:  Output the list
 <<:       Output operator
 -------------------------------------------------------------------------*/

#include <iostream>
using namespace std;
#ifndef STATICLIST
#define STATICLIST

const int CAPACITY = 1024;
template <class ElementType>
class StaticList
{

private:
    /******** Data Members ********/
    int mySize;                     // current size of list stored in myArray
    ElementType myArray[CAPACITY];  // array to store list elements


public:
    /******** Function Members ********/
    /***** Class constructor *****/
    StaticList();
    /*----------------------------------------------------------------------
     Construct a List object.

     Precondition:  None
     Postcondition: An empty List object has been constructed; mySize is 0.
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




}; //--- end of List class

//------ Prototype of output operator
template <class ElementType>
ostream& operator<< (ostream& out, const StaticList<ElementType>& aList);

#endif
// cpp
template <class ElementType>
StaticList<ElementType>::StaticList() :mySize(0)
{
}
template <class ElementType>
bool StaticList<ElementType>::empty() const
{
    return this->mySize == 0;
}
template <class ElementType>
void StaticList<ElementType>::insert(ElementType item, int pos)
{
    this->myArray[pos] = item; this->mySize++;
}
template <class ElementType>
void StaticList<ElementType>::erase(int pos)
{
    mySize--;
    for (int i = pos; i < this->mySize; i++)
    {
        this->myArray[i] = this->myArray[i + 1];
    }
}
template <class ElementType>
void StaticList<ElementType>::display(ostream& out) const
{
    for (int i = 0; i < this->mySize; i++)
    {
        out << this->myArray[i] << " ";
    }
    cout << endl;
}
template <class ElementType>
ostream& operator<<(ostream& out, const StaticList<ElementType>& aList)
{
    aList.display(out);
    return out;
}
