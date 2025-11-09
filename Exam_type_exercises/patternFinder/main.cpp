using namespace std;

#include <iostream>
#include <string>
#include <limits>
#include <iomanip>
#include <fstream>
#include <cstdlib>

void fillArr(int arr[], int dim);
void printArr(int arr[], int dim);
bool patternIsFound(int arr[], int arrDim, int pattern[], int pDim);



int main(){
    
    srand(time(NULL));

    int arr[6];
    int pattern[3];
    
    fillArr(arr, 6);
    printArr(arr, 6);
    
    fillArr(pattern, 3);
    printArr(pattern, 3);
    
    cout << patternIsFound(arr, 6, pattern, 3) << endl;

    return 0;
}


void fillArr(int arr[], int dim){
    for(int i = 0; i < dim; i++){
        arr[i] = rand() % 10 + 1;
    }
}

void printArr(int arr[], int dim){
    
    for (int i = 0; i < dim; i++)
    {
        if(i == 0){
            cout << "[ " << arr[i] << ", ";
        }
        else if (i == dim - 1)
        {
            cout << arr[i] << " ]" << endl;
        }
        else cout << arr[i] << ", ";
    }
    
}

bool patternIsFound(int arr[], int arrDim, int pattern[], int pDim){
    
    bool found = false;
    int i = 0;

    while(i <= arrDim - pDim && !found){

        found = true;
        for(int j = 0; j < pDim; j++){
            if(arr[i + j] != pattern[j]){
                found = false;
                break;
            }
        }
        i++;
    }
    return found;
}