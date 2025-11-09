using namespace std;

#include <iostream>
#include <string.h>

/******************************************************************************
    Implement calculate, which takes as first argument an option specifying the
    operation and then a list of numbers and performs the operation on the
    numbers  
    Variant: extend the implementation by controlling the execution of different
    functions: --sum, --product, --max, --average


 ****************************************************************************/




int multiply(int dim, char *argv[]);
void checkOperand(int dim, char *argv[]);
int Sum(int dim, char  *argv[]);
int Max(int dim, char  *argv[]);
void prepNumArray(int argc, char *argv[], int numArr[], int dim);
void cleanArr(int arr[], int dim);

int main (int argc, char * argv[])
{
    int prod;
    int numArr[10];

    prepNumArray(argc, argv, numArr, 10);
    //checkOperand(argc, argv);

    for(int i = 0; i <10; i++){

        cout << numArr[i] << endl;
    }
 

	return 0;
}

int multiply(int dim, char  * argv[]){

    int prod = 1;

    for(int i = 2; i < dim; i++){

        try{
            
            int n = stoi(argv[i]);
            prod *= n;

        }catch(invalid_argument){

            
            cout << "Could not transform " << argv[i] << " in integer" << endl;

        }
    }

    return prod;

}

void checkOperand(int dim, char *argv[]){

    const char *command = argv[1];
    //string command = argv[1];

    if( strcmp(command, "--sum") == 0){
        
        int sum = Sum(dim, argv);

        cout << "Sum of inserted numbers: "<< sum << endl;
        cout << command;
    }
    else if (strcmp(command, "--max") == 0){

        int max = Max(dim, argv);

        cout << "Maximum of inserted numbers: "<< max << endl;
        cout << command;

    }
    else if(strcmp(command, "--prod") == 0){

        int prod = multiply(dim, argv);

        cout << "Product of inserted numbers: "<< prod << endl;
        cout << command << endl;

    }else
        cout << "Invalid operand [ " << command << " ]" << endl;

}

int Sum(int dim, char * argv[]){
    
    
    int sum = 0;

    for(int i = 2; i < dim; i++){

        try{
            
            int n = stoi(argv[i]);
            sum += n;

        }catch(invalid_argument){

            cout << "Could not transform " << argv[i] << " in integer" << endl;

        }
    }

    return sum;

}


int Max(int dim, char * argv[]){
    
    
    int max = INT16_MIN;

    for(int i = 2; i < dim; i++){

        try{
            
            int n = stoi(argv[i]);
            if(n >= max){
                max = n;
            }
            

        }catch(invalid_argument){

            cout << "Could not transform " << argv[i] << " in integer" << endl;

        }
    }

    return max;

}

void prepNumArray(int argc, char *argv [], int numArr[], int dim){

    int n, i = 1, j = 0;


    cleanArr(numArr, dim);

    while(i < argc && j < dim) 

        try{
            int n = stoi(argv[i]);
            numArr[j] = n;
            j++;
        }
        catch(invalid_argument){

            cout << "Could not transform " << argv[i] << " in integer" << endl;
        }

        i++;
    


}

void cleanArr(int arr[], int dim){
    for(int i = 0; i < dim; i++){
        arr[i] = 0;
    }
}