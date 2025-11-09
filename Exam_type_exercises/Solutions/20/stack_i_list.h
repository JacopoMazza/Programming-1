#ifndef STACK_H
#define STACK_H

struct node {
	int value;
	node* next;
};
typedef node* listA;

void init();
bool push(int);
bool top(int &);
bool pop();
void deinit();

#endif