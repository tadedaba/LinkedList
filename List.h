/*
	**** This is the "List.h" header file. ****
	It contain the following three main parts.
		1. The class LinkedList
			=> This class hosts:
				--> The private data type struct
				--> The private function get_node()  
					to declare and initialize
					the struct object.  
				--> The public constructors 
					- LinkedList() declaration and implimentation
					- LinkedList(const LinkedList& source) declaration.
				--> The declaration of eight public functions & one friend function.
		2. The implementation of the friend function outside the class.
	Precondition for this program to run properly:
		=> The program works for integer data only. 
	Postcondition for the program 
		=> It can handle any number of items.
		=> It lists the items from smallest to the largest.
		=> It performs the following functions:
			-> retaining the copy of the original data
			-> inserting new item
			-> deleting an item
			-> re-initializing the list to empty
			-> searching and returning the kth value of the list
			-> looking up for an item in the list
			-> checking if the list content for emptiness
			-> print the list on the screen
			-> counting the number of items in the list.
*/
#include <iostream>
#ifndef _LIST
#define _LIST
#include <ostream>		//for the implementation of the friend function.
using namespace std;
class LinkedList{
	typedef int Item;	//type defination decoration. 
	private:
		struct Node{	// for the linked lists
			Item item;
			Node * next;
		};
		Node * first;
		Node * getNode(Item entry, Node * list);
	public:
		LinkedList(){		//default constructor
			first = NULL;
		}
		LinkedList(const LinkedList& source);	// copy constructor
		~LinkedList();	// destructor 
		// to re-initialize the list to empty. The make_empty() function 
		// is absent becouse it will have the same function as re_initialize()
		void re_Initialize(); 
		void insert(Item item);			//to insert items to the list
		void remove(Item item); 		//to remove items from the list
		void operator = (LinkedList source); //"="Operator overloading 
		bool isEmpty(); 			//to check if the list is empty or not
		int listLength(); 		//to get the number of nodes in the list
		bool isPresent(Item target); //to check if an item is in the list
		Item kthValue(int item);	//to access the kth item of the list
		//the friend function is used for the purpose of 
		//"<<" operator overloading. 
		friend ostream& operator << (ostream& out_s, const LinkedList& l); 
};
// Implimentation of the friend function.
ostream& operator << (ostream& out_s, const LinkedList& l){
	LinkedList::Node * ptr;
	ptr = l.first;
	while(ptr!=NULL){
		out_s << ptr -> item << ' ';
		ptr = ptr -> next;
	}
	return out_s;
}
#endif	//end of header file definition.
/* =======================================================================*/
