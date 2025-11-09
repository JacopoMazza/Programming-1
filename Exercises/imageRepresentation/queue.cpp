using namespace std;

#include "queue.h"


string dequeue(queue_node* &start){

    string ret = start -> value;
    queue_node *nextStart = NULL;
    
    nextStart = start -> next;
    delete start;
    start = nextStart;

    return ret;
}

void enqueue(queue_node* & start, string value){

    queue_node *newNode = createNode(value);

    if(start) insert_last(start, newNode);
    else insert_first(start, newNode);

}

void insert_last(queue_node* start, queue_node* newNode){

    while(start -> next){
        start = start -> next;
    }

    start -> next = newNode;
    newNode -> next = NULL;

}

void insert_first(queue_node* & start, queue_node* newNode){

    newNode -> next = start;
    start = newNode;
}

void printQueueNode(queue_node *n, int index){

    string out;

    cout << "Node " << index << endl;
    cout << "Value  :" << setw(20) << n -> value << endl;
    if(n -> next) {
        
        out.append("Node ");
        out.append(to_string(index + 1));
        cout << "Next   :" << setw(20) << out << endl << endl;
    }
    else cout << "Next   :" << setw(20) << "End" << endl << endl;
}

void printQueue(queue_node *start){
    
    int index = 1;

    cout << "Queue:" << endl;

    do
    {
        printQueueNode(start, index);
        start = start -> next;
        index ++;

    } while (start);


}

queue_node* createNode(string value){
    
    queue_node *newNode = new queue_node;
    newNode -> value = value;
    newNode -> next = NULL;

    return newNode;

}