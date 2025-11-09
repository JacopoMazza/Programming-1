using namespace std;
#include <iostream>

#include<stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void append_data(struct Node** head, int data) {
    //struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    struct Node* new_node = new Node;
    new_node->data = data;
    new_node->next = NULL;
    
    if (*head == NULL) {
        *head = new_node;
    } else {
        struct Node* last = *head;
        while (last->next != NULL) {
            last = last->next;
        }
        last->next = new_node;
    }
}

void interleave(struct Node** head1, struct Node** head2) {
    if (*head1 == NULL || *head2 == NULL) {
        return;
    }

    struct Node* curr1 = *head1;
    struct Node* curr2 = *head2;

    while (curr1 != NULL && curr2 != NULL) {
        struct Node* temp1 = curr1->next;
        struct Node* temp2 = curr2->next;

        curr1->next = curr2;
        curr2->next = temp1;

        curr1 = temp1;
        curr2 = temp2;
    }
}


// Function to print a linked list
void printList(struct Node* node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
}
int main() {
    struct Node* head1 = NULL;
    struct Node* head2 = NULL;
    
    // Add some nodes to the first linked list
    append_data(&head1, 1);
    append_data(&head1, 3);
    append_data(&head1, 5);
    append_data(&head1, 7);
        
    // Add some nodes to the second linked list
	append_data(&head2, 2);
    append_data(&head2, 4);
    append_data(&head2, 6);
    append_data(&head2, 8);
  
    cout << "Original Lists: " << endl; 
    cout << "List1: "; 
    printList(head1);
    cout << endl;
    cout << "List2: ";
    printList(head2);
    cout << endl;

    // Interleave the two linked lists alternatively
    interleave(&head1, &head2);
    cout << "After interleaving the two linked lists alternatively: " << endl; 
    cout << "List1: ";
    printList(head1);
    cout << endl;
    cout << "List2: ";   
    printList(head2);    
    cout << endl;
    return 0;
}
