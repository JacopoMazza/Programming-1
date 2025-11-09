/***************************************************************
 * implement a program that: creates 2 arrays with random size and fills them with random values
 * (from 0 to 30), then it creates a third array obtained by merging the other two arrays.
 * implement functions that:
 * - order the final array
 * - return max and min of that array,
 * - returns the average of the array,
 * - retursn the median of the array (if the size is odd, the median will be the central element
 * otherwise it will be the average of 2 central values)
 * 
 */


using namespace std;

#include <iostream>
#include <cstdlib>

void printArr(int* arr, int dim);
int* createArr(int dim);
int* mergeArr(int* arr1, int* arr2, int dim1, int dim2);
int getMedian(int* arr, int dim);
float getAverage(int* arr, int dim);
void sortArr(int* arr, int dim);

void fillArr(int* arr, int dim);

int main(){
    
    srand(time(NULL));

    int dim1 = rand() % 5 + 1;
    int dim2 = rand() % 5 + 1;
    
    int* arr1 = createArr(dim1);
    int* arr2 = createArr(dim2);
    
    fillArr(arr1, dim1);
    fillArr(arr2, dim2);

    printArr(arr1, dim1);
    printArr(arr2, dim2);

    int* mergedArr = mergeArr(arr1, arr2, dim1, dim2);
    printArr(mergedArr, dim1+dim2);

    sortArr(mergedArr, dim1+dim2);
    printArr(mergedArr, dim1 + dim2);

    float avg = getAverage(mergedArr, dim1 + dim2);
    int min = mergedArr[0];
    int max = mergedArr[dim1 + dim2 - 1];
    int median = getMedian(mergedArr, dim1+ dim2);


    return 0;

}

int* createArr(int dim){
    int* arr = new int[dim];

    return arr;
}

int* mergeArr(int* arr1, int* arr2, int dim1, int dim2){

    int* mergedArr = new int[dim1 + dim2];
    
    for(int i = 0; i < dim1; i++){
        mergedArr[i] = arr1[i];
    }

    for(int j = 0; j < dim2; j++){
        mergedArr[dim1 + j] = arr2[j];
    }

    return mergedArr;

}

void fillArr(int* arr, int dim){

    for(int i = 0; i < dim; i++){
        arr[i] = rand() % 21;
    }

}

void printArr(int* arr, int dim){
    
    for(int i = 0; i < dim; i++){
        cout << arr[i] << endl;
    }
    cout << endl;

}

int getMedian(int* arr, int dim){
    
    int median = 0;
    int medianInd = dim / 2;
    
    if(dim % 2 == 0){
        median = (arr[medianInd] + arr[medianInd - 1]) / 2; 
    }

    else
        median = arr[medianInd];

    return median;
}


float getAverage(int* arr, int dim){

    int sum = 0;

    for(int i = 0; i < dim; i++){
        sum += arr[i];
    }

    return float(sum)/float(dim);
}

void sortArr(int* arr, int dim){

    bool swap = true;


    while(swap){
        
        swap = false;

        for(int i = 0; i < dim - 1; i++){
            if(arr[i] > arr[i + 1]){
                
                int tmp;
                tmp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = tmp;
                swap = true;

            }
        }

        //printArr(arr, dim);
    }
  

}