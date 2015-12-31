/*This program is a Linked List using templates and creating a Linked List of strings.
A Linked List Using Templates and building a class Linked List. String names are used to build the List. 
This program has an add, remove, and display function*/
/* This linked list also can be seem as a STACK
 * because we add the value to the front of the list
 *
 */
#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_
#include <string>
#include <stdlib.h>
#include <iostream>
#include "listnode.h"
using namespace std;


template<class t>class linkedlist{
	
private:
	
		listnode<t> *head;
		
public:
		linkedlist() { head = NULL; } //constructor to initilaize a linkedlist
        ~linkedlist();                //destructor
		void add(t value);
		void remove(t value);
		void push_front(t value);
		void displaylist();
		void sortList();
		listnode<t> * getList();
		unsigned int size();
protected:
		void MergeSort(listnode<t>** headRef);
		listnode<t>* Merge(listnode<t>* left_list, listnode<t>* right_list);
		void split(listnode<t> **leftRef, listnode<t> **rightRef);


};
//Insert node at the end of the linked list
template<class t>void linkedlist<t>::add(t value) {
	
	 if (head == NULL)
		 head = new listnode<t>(value);
	
	else 
	{
		listnode<t> * nodeptr;
		nodeptr = head;
		while(nodeptr->next != NULL) {
			nodeptr = nodeptr->next;			
		}
		
		nodeptr->next = new listnode<t>(value); 
	}
	
}




template<class t>
listnode<t>* linkedlist<t>::getList(){

	return head;
}


template<class t>void linkedlist<t>::remove(t value) {
	
	listnode<t> * crtnode;
	listnode<t> * lastnode;
//	listnode<t> * temp;
	if(head == NULL) {		
		cout<<"the list is empty"<<endl; 
	}
	
	//Delet consecutive notes with same value from the beginning 
	while(head !=NULL && head->value == value)
	{
		listnode<t> *temp = head;
		head = head->next;
		free(temp);
	}
/*
	if(head->value == value) {
		crtnode = head; 
		head = crtnode->next;
	    delete crtnode;
        remove(t value); 		
	    }*/
	
/* this code works when all the node values are different 
        lastnode = NULL; 
		crtnode = head;
		while(crtnode != NULL) {
			if (crtnode->value == value) {
			    if(lastnode == NULL) {
				head = crtnode->next;
				}
			else {
				lastnode->next = crtnode->next;
			     }
			}
			lastnode = crtnode;
			crtnode = crtnode->next;
		}
	 free(crtnode);
	}	
	*/
	// http://www.ardendertat.com/2011/09/29/programming-interview-questions-5-linkedlist-remove-nodes/
	
	crtnode = head; // <- this is the new head node 
	                // which does not contain the remove value 
	while(crtnode->next!=NULL) {
		
		if(crtnode->next->value == value) {
			listnode<t> *temp = crtnode->next;
			crtnode->next = temp->next;
			free(temp);
		}
		else
		{
			crtnode=crtnode->next;
		}
	}
}

template <class t>linkedlist<t>::~linkedlist() {
	listnode<t> * nodeptr = head;
	while(nodeptr != NULL) {
		listnode<t> * garbage = nodeptr;
		nodeptr = nodeptr->next;
		delete garbage;
	}
}

template <class t>void linkedlist<t>::displaylist() {
	listnode<t> *nodeptr = head;

	while (nodeptr!=NULL) {
		cout<<nodeptr->value<<endl;
		nodeptr = nodeptr->next;
//		i++;
	}
//	cout<<i<<endl;
}


template <class t>
unsigned int linkedlist<t>::size() {

	listnode<t> *nodeptr;
 int count = 0;
	if(head == NULL)
		return 0;
	nodeptr = head;
	while(nodeptr != NULL)
	{
		nodeptr = nodeptr->next;
		count++;
	}

	return count;
}

template <class t>
void linkedlist<t>::push_front(t value){
	
	listnode<t> *nodeptr;
	
	if(head == NULL)
	head = new listnode<t>(value);
	else {
		
		nodeptr = new listnode<t>(value);
		nodeptr->next = head;
		head = nodeptr;
	//	delete nodeptr;
	}
}


template <class t>
void linkedlist<t>::sortList()
{
	MergeSort(&head);
}

template <class t>
void linkedlist<t>::MergeSort(listnode<t>** headRef){


	listnode<t>* left;
	listnode<t>* right;

	if((head == NULL) || (head->next == NULL))
		return;

	else {
		split(&left, &right);
		MergeSort(&left);
		MergeSort(&right);
	}

	head = Merge(left, right);
}

template <class t>
listnode<t>* linkedlist<t>::Merge(listnode<t>* left_list, listnode<t>* right_list){

	listnode<t>* sortedList = NULL;

	if(left_list == NULL)
		return right_list;
	if(right_list == NULL)
		return left_list;

	if(left_list->value <= right_list->value)
	{
		sortedList = left_list;
		sortedList->next = Merge(left_list->next,right_list);
	}
	else
	{
		sortedList = right_list;
		sortedList->next = Merge(left_list, right_list->next);
	}

	return sortedList;
}


template <class t>
void linkedlist<t>::split(listnode<t> **leftRef, listnode<t> **rightRef){

	//slow pointer increment once when fast incremented twice
	//when fast reach NULL slow will then points to the middle of the list

	listnode<t> *slow;
	listnode<t> *fast;


 	 if((head == NULL) || (head->next == NULL))
 	 {
 		 *leftRef = head;
 		 *rightRef = NULL;
 	 }

 	 else
 	 {
 		 slow = head;
 		 fast = head->next;

 		 while(fast != NULL)
 		 {
 			 fast = fast->next;
 			 if(fast != NULL)
 			 {
 				 slow = slow->next;
 				 fast = fast->next;
 			 }
 		 }
 	 }

 	 *leftRef = head;
 	 *rightRef = slow->next;
 	 slow->next = NULL;

}
#endif
