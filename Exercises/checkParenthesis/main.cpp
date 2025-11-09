using namespace std;

#include <iostream>

struct node {
    int value;
    node *next;
};

struct stack
{
    node *head;
};

//STACK
stack* initStack();
node* makeNode(int value);
int push(node* n, stack* s);
int pop(stack* s);
int getTop(stack* s);
void deinitStack(stack *s);
bool stackIsEmpty(stack * s);

//ARRAY
int getRealLenght(char list[], int dim);

bool isBalanced(stack *s, char list[], int dim);

int main(){
    
    int dim = 101;
    char formula[dim] = {'0'};

    stack *s = initStack();

    cout << "Insert formula (max 100 characters)" << endl;
    cin >> formula;

    cout << getRealLenght(formula, dim) << endl;
    
    if(isBalanced(s, formula, getRealLenght(formula, dim))){
        cout << "Formula is balanced" << endl;
    }else
        cout << "Formula is not balanced" << endl;

    return 0;
}






stack* initStack(){
    
    stack* newStack = new (nothrow) stack;
    
    if (newStack)
    {
        newStack -> head = NULL;
    }
    
    return newStack;

}

node* makeNode(int value){
    
    node *newNode = new node;

    if(newNode){
        newNode -> value = value;
        newNode -> next = NULL;
    }

    return newNode;

}

int push(node* n, stack* s){

    int retVal = 0;

    if(n){
        n -> next = s -> head;
        s -> head = n;
    }
    else
        retVal = 1;

    return retVal;

}

//returns INT_MIN if stack is empty;
int pop(stack* s){

    int retVal = INT_MIN;
    node *newStart;
    
    if (!stackIsEmpty(s))
    {
        retVal = s ->head ->value;
        newStart = s -> head -> next;
        delete s ->head;
        s -> head = newStart;
    }

    return retVal;
    
}


int getTop(stack* s){
    
    int retVal = INT_MIN;

    if(!stackIsEmpty(s)){
        retVal = s -> head -> value;
    }

    return retVal;
}


bool stackIsEmpty(stack * s){
    return s ->head == NULL;
}

void deinitStack(stack *s){
    delete s;
}


//ARRAY
int getRealLenght(char list[], int dim){
    
    int len = 0;

    for (int i = 0; i < dim; i++)
    {
        if (list[i] != '\0')
        {
            len++;
        }
    }
    
    return len;
}

bool isBalanced(stack *s, char list[], int dim){

    for (int i = 0; i < dim; i++)
    {
        if (list[i] == '(')
        {
            push(makeNode(int(list[i])), s);
        }
        
        else if (list[i] == ')' )
        {
            int res = pop(s);
            if (res == INT_MIN)
            {
                push(makeNode(int(list[i])), s);
            }
            
        }
        
        
    }

    return stackIsEmpty(s);
    
}