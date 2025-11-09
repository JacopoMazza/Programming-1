using namespace std;

#include <iostream>

//QUEUE

struct node {
    char value;
    node* next;
};

struct queue {
    node* head;
    node* tail;
};

enum return_value {Ok, Fail};

return_value queue_init(queue * &s);
return_value enqueue(queue* q, node * newNode);
return_value dequeue(queue* q, char &value);
bool queue_isEmpty(queue* q);
return_value nextValue(queue* q, char &value);

//STACK

struct stack{
    node* head;
};

return_value stack_init(stack* &s);
return_value push(stack* s, node * newNode);
return_value pop(stack* s, char &value);
bool stack_isEmpty(stack* s);
return_value getTop(stack* s, char &value);

return_value loadData(char word[], queue *q, stack *s);
return_value makeNode(char value, node* &newNode);
bool isPalindrome(queue* q, stack* s);

int main(){

    stack* s;
    queue* q;
    char word[101];

    if((queue_init(q) == Ok) && (stack_init(s) == Ok)){
        
        cout << "Insert the word to check (up to 100 chars)" << endl;
        cin >> word;

        if(loadData(word,q,s) == Ok){
            cout << isPalindrome(q,s) << endl;
        }

    }



    return 0;
}







//SHARED METHODS

return_value makeNode(char value, node* &newNode){
    
    newNode = new (nothrow) node;
    if(newNode == NULL){
        return Fail;
    }

    newNode ->value = value;
    newNode ->next = NULL;

    return Ok;
}

return_value loadData(char word[], queue *q, stack *s){
    
    int i = 0;
    if(word == NULL){
        return Fail;
    }

    while(word[i] != '\0'){

        node* newQueueNode, *newStackNode;
        if(makeNode(word[i], newQueueNode) == Ok && makeNode(word[i], newStackNode) == Ok){
            
            push(s, newStackNode);
            enqueue(q, newQueueNode);
        }

        i++;

    }

    return Ok;
}

bool isPalindrome(queue* q, stack* s){

    
    char st_value, q_value;

    while (!stack_isEmpty(s))
    {
        getTop(s, st_value);
        nextValue(q, q_value);
        if(!(st_value == q_value)){
            break;
        }

        pop(s, st_value);
        dequeue(q, q_value);

    }


    return stack_isEmpty(s);
    
    

}




//QUEUE

return_value queue_init(queue *&newQueue){
    
    
    newQueue = new (nothrow) queue;
    
    if(newQueue){
        newQueue -> head = NULL;
        newQueue -> tail = NULL;
        return Ok;    
    }

    return Fail;

}


return_value enqueue(queue* q, node * newNode){
    
    if(newNode == NULL){
        return Fail;
    }

    if(queue_isEmpty(q)){
        q ->head = newNode;
        q->tail = newNode;
    }
    else
    {
        q ->tail ->next = newNode;
        q ->tail = newNode;

    }

    return Ok;
}


return_value dequeue(queue* q, char &value){

    if(queue_isEmpty(q)){
        return Fail;
    }

    value = q -> head -> value;
    node* newHead = q->head ->next;
    delete q->head;
    q ->head = newHead;

    return Ok;
}


bool queue_isEmpty(queue* q){
    return q->head == NULL;
}

return_value nextValue(queue* q, char &value){
    
    if(queue_isEmpty(q)){
        return Fail;
    }

    value = q -> head ->value;

    return Ok;
}


//STACK

return_value stack_init(stack* &newStack){

    newStack = new (nothrow) stack;
    if(newStack == NULL){
        return Fail;
    }

    newStack ->head = NULL;
    return Ok;

}


return_value push(stack* s, node * newNode){
    
    if(newNode == NULL){
        return Fail;
    }

    newNode -> next = s ->head;
    s ->head = newNode;
    
    return Ok;
}

return_value pop(stack* s, char &value){
    
    if(stack_isEmpty(s)){
        return Fail;
    }

    value = s ->head->value;
    node *newHead = s ->head->next;
    delete s -> head;
    s->head = newHead;

    return Ok;
}


bool stack_isEmpty(stack* s){
    return s ->head == NULL;
}

return_value getTop(stack* s, char &value){
    
    if (stack_isEmpty(s))
    {
        return Fail;
    }

    value = s ->head -> value;

    return Ok;
    
}