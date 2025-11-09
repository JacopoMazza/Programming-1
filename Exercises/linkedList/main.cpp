using namespace std;

#include <iostream>
#include <string>
#include <limits>
#include <iomanip>


struct node {
    int value;
    node *next;
};

int get_lenght(node *start);
void insert_node(node* & start, int value);
void insert_first(node* & start, node* newNode);
void insert_last(node*, node*);
node* get_last(node *start);
void printNode(node *n, int index);
void printLinkedList(node *start);
void delete_node(node* & start, int value);
bool same_node(node*, node*);
void delete_first(node* & start);
void delete_specific_node(node* start, node* node);
void sorted_insertion(node * &start, node* newNode);
node* createNode(int value);
node* reverse_list(node *& start);
void reverse_list_helper(node *& start);


int main(){

    node *start = NULL;

    insert_node(start, 5);
    //printLinkedList(start);
    
    insert_node(start, 7);
    //printLinkedList(start);
    
    insert_node(start, 10);
    //printLinkedList(start);

    delete_node(start, 10);
    //printLinkedList(start);


    node * newNode = createNode(2);
    sorted_insertion(start, newNode);
    //printLinkedList(start);

    newNode = createNode(20);
    sorted_insertion(start, newNode);
    //printLinkedList(start);

    newNode = createNode(6);
    sorted_insertion(start, newNode);
    printLinkedList(start);

    get_lenght(start);

    reverse_list_helper(start);
    printLinkedList(start);

    return 0;
}


void insert_first(node* & start, node* newNode){

    newNode -> next = start;
    start = newNode;
}

void insert_last(node* start, node* newNode){

    while(start -> next){
        start = start -> next;
    }

    start -> next = newNode;
    newNode -> next = NULL;

}

void insert_node(node* & start, int value){

    node *newNode = new node;
    newNode -> value = value;
    newNode -> next = NULL;

    if(start) insert_last(start, newNode);
    else insert_first(start, newNode);

}


void printNode(node *n, int index){

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

void printLinkedList(node *start){
    
    int index = 1;

    cout << "Linked List:" << endl;

    do
    {
        printNode(start, index);
        start = start -> next;
        index ++;

    } while (start);


}

bool same_node(node* n, node* nToCompare ){

    return n == nToCompare;

}

void delete_first(node* & start){

    node *nextStart = NULL;
    
    nextStart = start -> next;
    delete start;
    start = nextStart;


}


void delete_node(node* & start, int value){

    bool targetIsHead;
    node *targetNode = start;
    while (true)
    {
        if(targetNode -> value == value){

            targetIsHead = same_node(targetNode, start);
            if (targetIsHead) delete_first(start);
            else delete_specific_node(start,targetNode);
            break;
        }
        else
            targetNode = targetNode -> next;
    }
    

}


void delete_specific_node(node* start, node* n){

    node *afterTarget = NULL;
    node *beforeTarget = NULL;
    bool found = false;

    if(start){

        while(!found && start){
            //check if i am at the previous to target
            if(same_node(start -> next, n)){
                found = true;
                beforeTarget = start;
                //check if target is last of the list
                if(start -> next == NULL) afterTarget = NULL;
                else afterTarget = start -> next -> next;
            }
            else
                start = start -> next;
        }

        delete n;
        beforeTarget -> next = afterTarget;
    }

    

}

void sorted_insertion(node *&start, node* newNode){
    
    node *cursorTarget = start, *cursToPrevious = start, *prevToTarget;
    bool insertionDone = false;

    //FIND TARGET
    while (cursorTarget -> next && !insertionDone)
    {
        if(newNode -> value > cursorTarget -> value){
            cursorTarget = cursorTarget -> next;
        }
        
        else
        {

            if(cursorTarget == start){
                insert_first(start, newNode);
                insertionDone = true;
                break;
            }

            else{

                //FIND PREVIOUS TO TARGET
                while(cursToPrevious -> next){
                    if (cursToPrevious -> next == cursorTarget)
                    {
                        prevToTarget = cursToPrevious;
                        break;
                    }

                    else
                        cursToPrevious = cursToPrevious -> next;
                    
                }
                
                prevToTarget -> next = newNode;
                newNode -> next = cursorTarget;
                insertionDone = true;
                

            }
            
        }
    }

    //it has to be inserted as tail
    if(!insertionDone && start){
        insert_last(start, newNode);
    }

    
    
}

node* createNode(int value){
    
    node *newNode = new node;
    newNode -> value = value;
    newNode -> next = NULL;

    return newNode;

}

int get_lenght(node *start){
    int lenght = 1;
    while (start -> next)
    {
        lenght++;
        start = start -> next;
    }
    
    return lenght;
}

node* reverse_list(node *& start){

    int len = get_lenght(start);

    //base case
    if(len == 1){
        return start;
    }

    else {
        node *nextToBeLast = start;
        for(int i = 0; i < len - 2; i++){
            nextToBeLast = nextToBeLast ->next;

        }

        node *nextFirst = nextToBeLast -> next;
        nextToBeLast -> next = NULL;

        nextFirst -> next = reverse_list(start);

        return nextFirst;
    }

}

void reverse_list_helper(node *& start){

        node *last = start;

        for(int i = 0; i < get_lenght(start) - 1; i++){
            last = last -> next;
        }

        reverse_list(start);

        start = last;

}