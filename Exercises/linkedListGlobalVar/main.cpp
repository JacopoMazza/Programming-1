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
void insert_node(int value);
void insert_first(node* newNode);
void insert_last(node* newNode);
node* get_last(node *start);
void printNode(node *n, int index);
void printLinkedList();
void delete_node( int value);
bool same_node(node*, node*);
void delete_first();
void delete_specific_node( node* node);
void sorted_insertion(node * &start, node* newNode);
node* createNode(int value);
node* reverse_list(node *& start);
void reverse_list_helper(node *& start);

node *head = NULL;


int main(){


    insert_node(5);
    //printLinkeList(start);
    
    insert_node(7);
    //printLinkedList(start);
    
    insert_node(10);
    

    insert_node(6);
    insert_node(8);

    printLinkedList();

    delete_node(5);
    printLinkedList();

    //delete_node(10);
    //delete_node(8);


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


void insert_first(node* newNode){

    newNode -> next = head;
    head = newNode;
}

void insert_last(node* newNode){

    node *cursor = head;

    while(cursor -> next){
        cursor = cursor -> next;
    }

    cursor -> next = newNode;
    newNode -> next = NULL;

}

void insert_node(int value){

    node *newNode = createNode(value);

    if(head) insert_last(newNode);
    else insert_first(newNode);

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

void printLinkedList(){
    
    int index = 1;
    node *cursor = head;

    cout << "Linked List:" << endl;

    do
    {
        printNode(cursor, index);
        cursor = cursor -> next;
        index ++;

    } while (cursor);


}

bool same_node(node* n, node* nToCompare ){

    return n == nToCompare;

}

void delete_first(){

    node *nextStart = NULL;
    
    nextStart = head -> next;
    delete head;
    head = nextStart;


}


void delete_node(int value){

    bool targetIsHead;
    node *targetNode = head;
    while (true)
    {
        if(targetNode -> value == value){

            targetIsHead = same_node(targetNode, head);
            if (targetIsHead) delete_first();
            else delete_specific_node(targetNode);
            break;
        }
        else
            targetNode = targetNode -> next;
    }
    

}


void delete_specific_node(node* n){

    node *afterTarget = NULL;
    node *beforeTarget = NULL;
    node *cursor = head;
    bool found = false;

    if(head){

        while(!found && cursor){
            //check if i am at the previous to target
            if(same_node(cursor -> next, n)){
                found = true;
                beforeTarget = cursor;
                //check if target is last of the list
                if(cursor -> next == NULL) afterTarget = NULL;
                else afterTarget = cursor -> next -> next;
            }
            else
                cursor = cursor -> next;
        }

        delete n;
        beforeTarget -> next = afterTarget;
    }

    

}

/*void sorted_insertion(node *&start, node* newNode){
    
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

    
    
}*/

node* createNode(int value){
    
    node *newNode = new node;
    newNode -> value = value;
    newNode -> next = NULL;

    return newNode;

}

int get_lenght(node *start){
    int lenght = 0;
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
        for(int i = 0; i < len - 1; i++){
            nextToBeLast = nextToBeLast ->next;

        }

        node *nextFirst = nextToBeLast -> next;
        nextToBeLast -> next = NULL;

        nextFirst -> next = reverse_list(start);

        return nextToBeLast;
    }

}

void reverse_list_helper(node *& start){

        node *last = start;

        for(int i = 0; i < get_lenght(start) ; i++){
            last = last ->next;
        }

        reverse_list(start);

        start = last;

}