using namespace std;
#include <iostream>
#include <string>
#include <limits>
#include <iomanip>
#include <fstream>

struct node{

    int value;
    node* left;
    node* right;

};

node* makeNode(int val);
void insertNode(node* root, node* newNode);
void printTree(node *root, int level);
void printTreeAscOrder(node* root);
void insertNodeRecursive(node* root, node* newNode, bool to_right, node* father);
string searchNum(node* root, int val);
void getPathToNum(node* root, int val, string &path);
bool isInTree(node* root, int target);
void deleteTree(node* &root);
bool is_bst(node* root);
void printTopDown(node *root, int hor_space, int level);
int getTreeHeight(node *root);

int main(int argc, char * argv[]){

    fstream fread;
    string num;
    node* root;



    fread.open("nums.txt", ios_base::in);

    fread >> num;
    root = makeNode(stoi(num));

    while(!fread.eof()){
        
        fread >> num;
        
        node* newNode = makeNode(stoi(num));
        //insertNode(root, newNode);
        insertNodeRecursive(root, newNode, false, nullptr);

    }
    
    insertNodeRecursive(root, makeNode(1), false, nullptr);
    printTree(root, 0);
    printTreeAscOrder(root);
    cout << endl;

    
    //string path = searchNum(root, 2);
    //cout << path << endl;

    //cout << is_bst(root) << endl;

    //printTopDown(root, 0, 0);
    cout << getTreeHeight(root) << endl;

    deleteTree(root);
}

node* makeNode(int val){

    node* newNode = new node;
    newNode -> value = val;
    newNode -> left = NULL;
    newNode -> right = NULL;

    return newNode;
}

void insertNode(node* root, node* newNode){

    node* cursor = root;
    bool inserted = false;

    while (!inserted)
    {
        if(newNode -> value > cursor -> value){
            
            if (cursor ->right)
            {
                cursor = cursor ->right;
            }
            else{
                cursor -> right = newNode;
                inserted = true;
            }
        }
        
        else
        {
            if (cursor ->left)
            {
                cursor = cursor ->left;
            }
            else{
                
                cursor -> left = newNode;
                inserted = true;
            }

        }
    }
    
}

void printTree(node* root, int level){
    
    //Go down right path as they are the first to be printed
    if(root ->right){
        printTree(root -> right, level + 1);
    }
    
    //print current node
    for(int i = 0; i < level; i++){
        cout << "\t";
    }
    cout << root ->value << endl;
    
    //Go down left path
    if(root ->left){
        printTree(root ->left, level +1);
    }
    

}

void printTreeAscOrder(node* root){

    //GO DOWN LEFT PATH AS THEY ARE THE MINIMUM NUMBERS
    if(root -> left){
        printTreeAscOrder(root ->left);
    }

    cout << root ->value << ",";

    if(root ->right){
        printTreeAscOrder(root ->right);
    }


}

void insertNodeRecursive(node* root, node* newNode, bool to_right, node* father){

    if(!root){
        
        if(to_right){
            father ->right = newNode;
        }else
            father -> left = newNode;

        return;
    }

    if (newNode ->value > root ->value)
    {
        insertNodeRecursive(root ->right, newNode, true, root);
    }
    else
        insertNodeRecursive(root ->left, newNode, false, root);
    

 

}

string searchNum(node* root, int target){

    string path = "";
    bool targetInTree = isInTree(root, target);

    if(targetInTree){
        getPathToNum(root, target, path);
    }

    return path;

}

void getPathToNum(node* root, int target, string &path){
    
    if(target == root -> value) return;
    else{
        
        path += (to_string(root -> value) + ",");
        if(target > root ->value){
            path += "right," ;
            getPathToNum(root ->right,target, path);
        }
        else{
            path += "left," ;
            getPathToNum(root ->left,target, path);
        }
    }

}

bool isInTree(node* root, int target){

    bool targetIsGreater;
    
    if(root ->value == target) return true;
    
    else{
        
        targetIsGreater = target > root ->value;
        if(targetIsGreater && root ->right){
            isInTree(root -> right, target);
        }
        else if (targetIsGreater && !root ->right)
        {
            return false;
        }
        else if (!targetIsGreater && root ->left)
        {
            isInTree(root ->left, target);
        }
        else
            return false;
        
    }

}

void deleteTree(node* &root){

    if(root -> right){
        deleteTree(root ->right);
    }

    if(root ->left){
        deleteTree(root ->left);
    }

    delete root;
    root = NULL;

}

/*bool is_bst(node* root){

    if(root -> right){
        if(root ->right ->value > root ->value){
            is_bst(root ->right);
        }
        else
            return false;
    }

    
    if(root ->left){
        if(root ->left ->value < root ->value){
            is_bst(root ->left);
        } 
        else
            return false;
    }

}*/

void printTopDown(node *root, int hor_space, int level){
    
    if(root ->left){
        printTopDown(root ->left, hor_space, level + 1);
    }
    
    for (int i = 0; i < level; i++)
    {
        cout << endl;
    }
    
    for(int i = 0; i < hor_space; i++){
        cout << "\t";
    }
    cout << root ->value << endl;
    
    
    if(root ->right){
        printTopDown(root ->right,  hor_space + 1, level + 1);
    }
}

int getTreeHeight(node *root){
    
    if(!root){
        return 0;
    }

    else{
        return 1 + max(getTreeHeight(root -> right), getTreeHeight(root ->left));
    }
}