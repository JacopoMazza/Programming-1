#ifndef QUEUE_H
#define QUEUE_H

const int MAX_DIM = 31;

struct node {
	char* name;
	node* next;
};
typedef node* listA;

struct queue {
    listA tail;
    listA head;
};

void init ();
bool enqueue(char *);
bool first(char * &);
bool dequeue();
void deinit();
void print();

#endif



