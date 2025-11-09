using namespace std;

#include <iostream>
#include <string>
#include <limits>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include <cstring>

struct node{
    char* clientName;
    node* next;
};

struct queue{
    node* head;
    node* tail;
};

queue* init_queue();
void enqueue(node* newNode, queue* q);
char* dequeue(queue* q);
void printQueue(queue *q);
void insert_client(queue* q);
node* makeNode(char* value);
void printName(char* name);
char* lookup(queue* q);



int main(){

    
    int cmd;

        
    queue* q;
    q = init_queue();

    do
    {
        cout << "Choose the operation" << endl;
        cout << "1) Add a Client" << endl;
        cout << "2) Serve a Client" << endl;
        cout << "3) Look at the queue" << endl;
        cout << "4) Exit" << endl;
        cin >> cmd;
        cin.ignore(100, '\n');

        switch (cmd)
        {
        case 1:
            insert_client(q);
            break;
        case 2:
            cout << "Client ";
            printName(dequeue(q));
            cout << " has been served!" << endl << endl;
            break;
        case 3:
            printQueue(q);
            break;
        
        default:
            cout << "Operation not available!, Exiting now..." << endl << endl;
            break;
        }
    } while (cmd != 4);
    


    return 0;
}

queue* init_queue(){
    queue* q = new queue;
    q -> head = nullptr;
    q ->tail = nullptr;
    return q;
}

void enqueue(node* newNode, queue* q){
    if(!(q ->head)){
        q -> head = newNode;
        q ->tail = newNode;
    }
    else
    {
        q -> tail -> next = newNode;
        q ->tail = newNode;
    }
}


char* dequeue(queue* q){
    
    if(q ->head){
        
        char* value = new char[strlen(q->head ->clientName) + 1];
        strcpy(value, q->head->clientName);

        node* nextHead = q ->head ->next;
        delete[] q ->head ->clientName;
        delete q ->head;

        q ->head = nextHead;

        return value;
    }

    else{
        return nullptr;
    }



}

void printQueue(queue *q){

    node* cursor = q ->head;
    if(cursor){
        while (cursor ->next)
        {
            printName(cursor ->clientName);
            cout << " -> ";
            cursor = cursor -> next;
        }
        printName(cursor ->clientName);
        cout << endl;
    }
    else{
        cout << "All clients have been served, the queue is empty!" << endl << endl;
    }

    
}

void insert_client(queue* q){

    char client[31];
    cout << "Insert Client Name" << endl;
    cin.getline(client, 31);
    
    if(!cin.fail()){

        enqueue(makeNode(client), q);
        if(q -> head){
            cout <<"Client added succesfully!" << endl;
        }
    }
    else{
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    


}

node* makeNode(char* value){
    
    node* newNode = new node;
    newNode ->clientName = new char[strlen(value) + 1];
    strcpy(newNode ->clientName, value);
    newNode ->next = nullptr;

    return newNode;
}

void printName(char* name){
    
    /*for(int i = 0; i < 30 && *(name + i) != '\0'; i++){
            cout << *(name + i);
    }*/

   for(int i = 0; i < 30 && name[i] != '\0'; i++){
        cout << name[i];
   }
}
