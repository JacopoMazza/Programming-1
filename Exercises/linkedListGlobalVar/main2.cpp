using namespace std;

#include <iostream>
#include <string>
#include <limits>
#include <iomanip>


struct node {
    int value;
    node *next;
};

void insert_node(int value);
void insert_first(node* newNode);
void insert_last(node*, node*);
void printNode(node *n, int index);
void printLinkedList(node *start);

node *head = NULL;


int main(){


    insert_node(5);
    //printLinkeList(start);
    
    insert_node(7);
    //printLinkedList(start);
    
    insert_node(10);
    printLinkedList(head);

    //delete_node(start, 10);
    //printLinkedList(start);


    /*node * newNode = createNode(2);
    sorted_insertion(start, newNode);
    //printLinkedList(start);

    newNode = createNode(20);
    sorted_insertion(start, newNode);
    //printLinkedList(start);

    newNode = createNode(6);
    sorted_insertion(start, newNode);
    printLinkedList(start);

    reverse_list_helper(start);
    printLinkedList(start);
*/
    return 0;
}