using namespace std;

#include <iostream>
#include <string>
#include <limits>
#include <iomanip>
#include <fstream>

struct node {
    int value;
    node *next;
};

struct stack
{
    node *head;
};

stack* initStack();
node* makeNode(int value);
int push(node* n, stack* s);
int pop(stack* s);
int getTop(stack* s);
void deinitStack(stack *s);
bool stackIsEmpty(stack * s);

void writeToFile(stack * s);


int main(int argc, char * argv[]){

    fstream fread;
    string num;
    stack* st;

    st = initStack();

    fread.open("test.txt", ios_base::in);

    while (fread >> num)
    {
        
        
        try
        {
            push(makeNode(stoi(num)), st);
        }
        catch(invalid_argument)
        {
            cout << "Cannot convert to number!" << endl;
        }
        
        
        
        if (fread.eof())
        {
            break;
        }


    }

    writeToFile(st);
    

    return 0;
}

void writeToFile(stack * s){

    fstream fwrite;
    int val;
    string to_write = "";

    fwrite.open("output.txt", ios_base::out);
    while (!stackIsEmpty(s))
    {
        val = pop(s);
        if (getTop(s) == INT_MIN)
        {
            to_write += to_string(val);
            break;
        }
        
        to_write += to_string(val) + "\n";

    }
    
    fwrite << to_write;
    fwrite.close();
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
    else
        cout << "The stack is empty!" << endl;

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