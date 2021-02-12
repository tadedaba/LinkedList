/*
	**** This is the "List.cpp" implementation file  ****
	This file implements all the functions defined in the 
	"List.h" header file. Hence it is the file for class
	implimentation. 
*/
#include <iostream>
#include "List.h"
#include <cstddef>

using namespace std;
LinkedList::Node * LinkedList::getNode(Item entry, Node * list){
	Node * temp;
	temp = new Node;
	temp->item = entry;
	temp->next = list;
	return temp;
}
LinkedList::LinkedList(const LinkedList& source){
	Node * ptr;
	Node * last;
	if(source.first == NULL)
		first = NULL;
	else{
		first = getNode(source.first -> item, NULL);
		last = first;
		ptr = source.first -> next;
		while(ptr != NULL){
			last->next = getNode(ptr->item, NULL);
			last = last->next;
			ptr  = ptr->next;
		}
	}
}
LinkedList::~LinkedList(){
	Node * temp;
	while(first != NULL){
		temp = first;
		first = first->next;
		delete temp;
	}
}
void LinkedList::operator =(LinkedList source){
	Node * ptr;
	Node * last;
	LinkedList empty;
	if(&source != this){
		empty.~LinkedList();
		
		first = getNode(source.first -> item, NULL);
		last = first;
		ptr = source.first -> next;
		while(ptr != NULL){
			last->next = getNode(ptr->item, NULL);
			last = last->next;
			ptr  = ptr->next;
		}
	}
	else return;
}                                                                                                                                                                                                                                                                                                                                                                                                                 
int LinkedList::listLength(){
	Node * ptr;
	int count = 0;
	ptr = first;
	while(ptr != NULL){
		++count;
		ptr = ptr->next;
	}
	return count;
}
bool LinkedList::isEmpty(){
	Node * ptr;
	ptr = first;
	if(ptr == NULL)
		return true;
	else return false;
}
bool LinkedList::isPresent(Item target){
	Node * ptr;
	ptr = first;
	while(ptr != NULL && ptr -> item != target){
		ptr = ptr -> next;
	}
	return ptr != NULL;
}
void LinkedList::insert(Item newItem){
	Node* prev;
	if(first == NULL || newItem < first -> item)
		first = getNode(newItem, first);
	else{
		prev = first;
		while(prev -> next != NULL && prev -> next -> item < newItem)
			prev = prev ->next;
		prev -> next = getNode(newItem, prev -> next);
	}
}
void LinkedList::remove(Item oldItem){
	Node * prev;
	Node * temp;
	prev = first;
	if(first -> item == oldItem){
		first = first -> next;
		delete prev;
	}
	else{
		while(prev -> next ->item < oldItem)
			prev = prev -> next;
		temp = prev -> next;
		prev -> next = temp -> next;
		delete temp;
	}
}
LinkedList::Item LinkedList::kthValue(Item k){
	Node * prev;
	prev = first;
	for(int i = 0; i < k; i++)
		prev = prev -> next;
	return prev -> item;
}
void LinkedList::re_Initialize(){
	Node * prev;
	prev = first;
	if(prev == NULL){}
	else{
		LinkedList empty;
		empty.~LinkedList();
	}
}
/* =======================================================================*/
