/**********************************************************************
 * implement a progam that creates an array of dimension X(less than 16) randomly generated and 
 * fills the array with randomly generated numbers,
 * then implement a function that fills a doubly linked list with the values of the array.
 * - implement a functions that prints the doubly linked list in forward direction.
 * - implement an insertion function in a specific position where the position is given by the user and
 * passed to the function
 *
 * 
 * 
 * 
 */



using namespace std;

#include <iostream>
#include <cstdlib>


struct Node{
    
    Node* next;
    Node* prev;
    int data;
};

int* createArr(int dim);
void fillArr(int* arr, int dim);
void insert_first(Node* &head, Node* newNode);
void insert_last(Node* head, Node* newNode);
void insertNode(Node *& head, int data);
Node* make_node(int data);
void createListFromArr(int *arr, int dim, Node* &head);
void printList(Node* head);
int getListLenght(Node* head);
void insertAtPosition(Node* &head, int position, Node* newNode);
void printArr(int* arr, int dim);

int main(){
    
    
    
    srand(time(NULL));
    Node* head = NULL;

    int arrDim = rand() % 15 + 1;
    int* arr = createArr(arrDim);

    

    createListFromArr(arr, arrDim , head);
    printList(head);

    int position;
    cout << "Enter position" << endl;
    cin >> position;
    if(!cin.fail()){
        insertAtPosition(head, position, make_node(10));
        printList(head);
    }

    return 0;


}


void insert_first(Node* &head, Node* newNode){
    newNode ->prev = NULL;
    newNode ->next = head;
    head = newNode;
}

void insert_last(Node* head, Node* newNode){
    Node* cursor = head;
    
    while(cursor -> next){
        cursor = cursor -> next;
    }

    newNode -> prev = cursor;
    newNode ->next = NULL;
    cursor -> next = newNode;

}

void insertNode(Node *& head, int data){

    Node* newNode = make_node(data);

    if(head) insert_last(head, newNode);
    else insert_first(head, newNode);
}

Node* make_node(int data){
    
    Node* newNode = new Node;
    newNode -> data = data;
    newNode -> prev = NULL;
    newNode -> next = NULL;

    return newNode;
}

void createListFromArr(int *arr, int dim, Node* &head){
    for(int i = 0; i < dim; i++){
        insertNode(head, arr[i]);
    }
}

void printList(Node* head){
    
    Node* cursor = head;
    while (cursor -> next)
    {
        cout << cursor ->data << " -> ";
        cursor = cursor ->next;
    }
    cout << cursor -> data << endl;
}


int getListLenght(Node* head){
    
    int len = 1;
    while(head ->next){
        len++;
        head = head ->next;
    }

    return len;

}

int* createArr(int dim){
    
    int* arr = new int[dim];

    fillArr(arr, dim);
    
    return arr;
}

void fillArr(int* arr, int dim){

    for(int i = 0; i < dim; i++){
        arr[i] = rand() % 21;
    }

}

void insertAtPosition(Node* &head, int position, Node* newNode){
    Node* cursor = head;
    int listLen = getListLenght(head);
    if (position <= listLen)
    {
        
        if(position == 1){

            newNode ->next = head;
            newNode ->prev = NULL;
            head -> prev = newNode;
            head = newNode;

        }
        
        else{
            
            for (int i = 1; i < position; i++)
            {
                cursor = cursor -> next;
            }

            newNode ->prev = cursor ->prev;
            cursor ->prev ->next = newNode;

            newNode ->next = cursor;
            cursor ->prev = newNode;
        }
        

        
    }
    


}

void printArr(int* arr, int dim){
    
    for(int i = 0; i < dim; i++){
        cout << arr[i] << endl;
    }
    cout << endl;

}