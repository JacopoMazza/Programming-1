using namespace std;

#include <iostream>
#include <string>
#include <limits>
#include <iomanip>
#include <fstream>
#include <cstdlib>

struct node{
    int val;
    node* next;
};

void insert_first(node* &head, node* newNode);
void insert_last(node* head, node* newNode);
void insert_node(node* &head, node* newNode);
void printList(node* head);
int countOccurencies(node* head, int target);
node* makeNode(int val);
void getWarningList(node* employeesHead, node*enterHead, node*exitHead, node* &warningHead);


int main(){

    node* employeesHead = nullptr, *enterHead = nullptr, *exitHead = nullptr, *warningHead = nullptr;

    //employees list
    insert_node(employeesHead, makeNode(10));
    insert_node(employeesHead, makeNode(14));
    insert_node(employeesHead, makeNode(20));

    //enter list
    insert_node(enterHead, makeNode(10));
    insert_node(enterHead, makeNode(10));
    insert_node(enterHead, makeNode(14));
    insert_node(enterHead, makeNode(14));
    insert_node(enterHead, makeNode(20));

    //exit list
    insert_node(exitHead, makeNode(10));
    insert_node(exitHead, makeNode(10));
    insert_node(exitHead, makeNode(14));
    insert_node(exitHead, makeNode(20));
    insert_node(exitHead, makeNode(14));
    
    
    printList(employeesHead);
    printList(enterHead);
    printList(exitHead);
    

    getWarningList(employeesHead, enterHead, exitHead, warningHead);
    if(warningHead){
        printList(warningHead);
    }
    else{
        cout << "Warning List is empty!" << endl;
    }



    return 0;
}

void insert_first(node* &head, node* newNode){
    head = newNode;
}

void insert_last(node* head, node* newNode){
    node* cursor = head;
    while(cursor -> next){
        cursor = cursor ->next;
    }

    cursor ->next = newNode;
}

void insert_node(node* &head, node* newNode){
    if(!head){
        insert_first(head, newNode);
    }
    else{
        insert_last(head, newNode);
    }
}

void printList(node* head){
    
    node* cursor = head;
    while(cursor -> next){
        cout << cursor ->val << " -> ";
        cursor = cursor ->next;
    }
    cout << cursor ->val << endl;

}

int countOccurencies(node* head, int target){
    
    int count = 0;
    node* cursor = head;
    
    if(head){
        
        while(cursor){
            if(cursor ->val == target){
                count++;
            }
            cursor = cursor ->next;
        }
    }

    return count;
}

node* makeNode(int val){
    node* newNode = new node;
    newNode ->val = val;
    newNode ->next = nullptr;

    return newNode;
}

void getWarningList(node* employeesHead, node*enterHead, node*exitHead, node*&warningHead){

    int enterCount, exitCount;

    if(employeesHead){
        while(employeesHead){
            
            enterCount = countOccurencies(enterHead, employeesHead ->val);
            exitCount = countOccurencies(exitHead, employeesHead ->val);
            if(enterCount != exitCount){
                insert_node(warningHead, makeNode(employeesHead ->val));
            }
            employeesHead = employeesHead ->next;
        }
    }
}