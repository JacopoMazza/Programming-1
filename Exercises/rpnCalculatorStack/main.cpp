using namespace std;

#include <iostream>
#include <string>
#include <limits>
#include <iomanip>

struct node {
    int value;
    node *next;
};

void push(node* & start, node* newNode);
int pop(node* & start);
void printStack(node *start);
node* createNode(int value);
void printNode(node *n, int index);
bool isInList(string[], string, int len);
void solve(node *start, string operand);


int main() {

    bool exit = false;
    string exp;
    string operands[] = {"+", "-", "*", "/"};
    node* start = NULL;

    int len = sizeof(operands) / sizeof(operands[0]);

    while(!exit){

        cout << "Inserire espressione" << endl;
        cin >> exp;

        try
        {
            int num = stoi(exp);
            push(start, createNode(num));
            printStack(start);
        }
        catch(invalid_argument)
        {
            cout << "The expression is not an integer" << endl;
            if (isInList(operands, exp, len))
            {
                cout << "Expression is an operand" << endl;
                solve(start, exp);
            }
            else if (exp.compare("s") == 0)
            {   
                cout << "Swap!" << endl;
                //swap();
            }
            else{
                cout << "Inavlid Expression" << endl << endl;
                exit = true;
            }
                
            
            
        }
        
    }

    return 0;
}




void push(node* & start, node* newNode){

    newNode -> next = start;
    start = newNode;
}

void printStack(node *start){
    
    int index = 1;

    cout << "Linked List:" << endl;

    do
    {
        printNode(start, index);
        start = start -> next;
        index ++;

    } while (start);


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

int pop(node* & start){

    node *nextStart = NULL;
    int val;

    val = start -> value;
    
    nextStart = start -> next;
    delete start;
    start = nextStart;

    return val;

}

node* createNode(int value){
    
    node *newNode = new node;
    newNode -> value = value;
    newNode -> next = NULL;

    return newNode;

}



bool isInList(string arr[], string elem, int len){
    
    for(int i = 0; i < len; i++){
        if(elem.compare(arr[i]) == 0){
            return true;
        }
    }

    return false;
}

void solve(node *start, string operand){
    //toComplete
}