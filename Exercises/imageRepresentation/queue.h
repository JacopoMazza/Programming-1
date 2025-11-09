using namespace std;

#include <string>
#include <iostream>
#include <iomanip>

struct queue_node {
    string value;
    queue_node *next;
};

queue_node* createNode(string value);
void enqueue(queue_node* & start, string value);
void insert_first(queue_node* & start, queue_node* newNode);
void insert_last(queue_node*, queue_node*);
string dequeue(queue_node* & start); 
void printQueue(queue_node *start);
void printQueueNode(queue_node *n, int index);