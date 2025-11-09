#include <iostream>
#include <cstring>
#include "queue_c_list.h"

using namespace std;

static queue Q;

static bool empty() {
  return (Q.head == NULL);
}


void init() {
  Q.head = NULL;
}


bool enqueue(char * n) {
  
    bool resultOperation;
    listA newNode = new (nothrow) node;
    char * tmp = new (nothrow) char[MAX_DIM];
    if (newNode==NULL) {
        resultOperation = false;
    }
    else {
        strcpy(tmp, n);
        newNode->name=tmp;
        newNode->next=NULL;
        if (empty()) {
            Q.head=newNode;
        }
        else { 
            Q.tail->next=newNode;
        }
        Q.tail=newNode;
        resultOperation = true;
    }
    return resultOperation;
}


bool first(char * &n) { 
    bool resultOperation;
    if (empty()) {
        resultOperation = false;
    }
    else {
        n = Q.head->name;
        resultOperation = true;
    }
    return resultOperation;
}


bool dequeue() { 
    bool resultOperation;
    if (empty()) {
        resultOperation = false;
    }
    else {
        listA firstNode;
        firstNode = Q.head;
        Q.head = Q.head->next;
        delete firstNode; 
        resultOperation = true;
    }
    return resultOperation;
}

void deinit() {
    char * tmp;
	while(first(tmp)) {
        delete[] tmp;
		dequeue();
	}
}

void print() {

  if (!empty()) {
    listA currenntNode=Q.head;
    do {
      cout << currenntNode->name << endl;
      currenntNode = currenntNode->next;
    } while (currenntNode != NULL);
  }
}
