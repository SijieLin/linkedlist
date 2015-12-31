#ifndef LISTNODE_H_
#define LISTNODE_H_

#include <iostream>
using namespace std;

template <class t>class listnode {
		 
public: 
       t value;
	   listnode* next;
       listnode();
	   listnode(t value1, listnode * next1 = NULL)
			{
				value = value1;
				next = next1;
			}

};

#endif
