#include <iostream>
#include "stack_i_list.h"

using namespace std;

static listA stack;

static bool empty () {
	return (stack == NULL);    
}


void init() {
	stack = NULL;
}


bool top (int &n) {
	
	bool resultOperation;
	if (empty()) {
		resultOperation = false;
	}
	else {
		n=stack->value;
		resultOperation = true;
	}
	return resultOperation;
}


bool push (int n) {

	bool resultOperation;
	listA newNode = new (nothrow) node;
	if (newNode==NULL) {
		resultOperation = false;
	}
	else {
		newNode->value = n;
		newNode->next = stack;
		stack = newNode;
		resultOperation = true;
	}
	return resultOperation;
}


bool pop () {
	
	bool resultOperation;
	if (empty()) {
		resultOperation = false;
	}
	else {
		listA firstNode = stack;
		stack = stack->next;
		delete firstNode;
		resultOperation = true;
	}
	return resultOperation;
}

void deinit() {
    int tmp;
	while(top(tmp)) {
		pop();
	}
}