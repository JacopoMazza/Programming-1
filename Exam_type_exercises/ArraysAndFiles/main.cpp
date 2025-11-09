using namespace std;

#include <iostream>
#include <string>
#include <limits>
#include <iomanip>
#include <fstream>
#include <cstdlib>

int  getRowsCount(string filename);
void fillArray(int* arr, int dim);
void findAndPrintDistinct(int* arr);
void printArr(int* arr);
void fillRowsArray(string *rowsArray, string filename);
void createArraysBasedOnRows(string *rowsArray, int** finalArrays, int size, int* sizesArray);
int getWordCount(string line);
void fillArray(string row, int* arrToFill, int arrToFillSz);
int countOccInArr(int arr[], int dim, int target);
int countPairsToSum(int arr[], int dim, int targetSum);

int main(){
    
    fstream fread;
    string line = "";
    int wordCount = 0;
    int arraysPos = 0;

    srand(time(NULL));

    int rowsCount = getRowsCount("input.txt");
    string* rowsArray = new string[rowsCount];
    int* sizesArray = new int[rowsCount];
    int** arrays = new int*[rowsCount];


    
    
    
    fread.open("input.txt", ios_base::in);

    while(!fread.eof()){
        
        wordCount = 0;
        getline(fread, line);
        for(int i = 0; i < line.length(); i++){
            if(line[i] == ' '){
                wordCount++;
            }
        }
        arrays[arraysPos] = new int[wordCount + 2];
        fillArray(arrays[arraysPos], wordCount + 2);
        arraysPos++;
        
    }

    for(int i = 0; i < rowsCount; i++){
        printArr(arrays[i]);
    }
    
    findAndPrintDistinct(arrays[1]);



    
    


    return 0;
}

int getRowsCount(string filename){
    fstream fread;
    string line;
    int rowCount = 0;

    fread.open(filename, ios_base::in);
    
    while (!fread.eof())
    {
        getline(fread, line);
        rowCount++;

    }

    fread.close();
    return rowCount;
}

void fillArray(int* arr, int dim){
    for(int i = 0; i < dim - 1; i++){
        arr[i] = rand() % 10;
    }
    arr[dim - 1] = INT_MIN;
}

void findAndPrintDistinct(int* arr, int dim){

    int i = 0;
    int count = 0;
    
    for(int i = 0; i < dim; i++){
        
        if(countOccInArr(arr, dim, arr[i]) == 1){
            cout << arr[i] << " ";
        }
    }
    
    
    
    
    while (arr[i] != INT_MIN)
    {
        int j = 0;

        while(arr[j] != INT_MIN){
            if(arr[j] == arr[i] && j != i){
                count++;
            }
            j++;
        }

        if(count == 0){
            cout << arr[i] << " ";
        }

        i++;
        count = 0;
    }
    cout << endl;

}

void printArr(int* arr){
    
    int i = 0;
    while (arr[i] != INT_MIN)
    {
        cout << arr[i] << ", ";
        i++;
    }
    cout << endl;
 
    
}

void fillRowsArray(string *rowsArray, string filename){
    fstream fread;
    fread.open(filename, ios_base::in);
    string line;

    int i = 0;
    while (fread.eof())
    {
        getline(fread, line);
        rowsArray[i] = line;

    }
    fread.close();
}

void createArraysBasedOnRows(string *rowsArray, int** finalArrays, int size, int* sizesArray){
    for(int i = 0; i < size; i++){
        finalArrays[i] = new int[getWordCount(rowsArray[i])];
        sizesArray[i] = getWordCount(rowsArray[i]);
    }
}

int getWordCount(string line){
    int wordCount = 0;
    for(int i = 0; i < line.length(); i++){
        if(line[i] == ' '){
            wordCount++;
        }
    }

    return wordCount + 1;
}

void fillArray(string row, int* arrToFill, int arrToFillSz){
    for(int i = 0; i < arrToFillSz; i++){

    }
}

int countOccInArr(int arr[], int dim, int target){
    int occ = 0;
    for(int i = 0; i < dim; i++){
        if(arr[i] == target){
            occ++;
        }
    }

    return occ;
}

int countPairsToSum(int arr[], int dim, int targetSum){
    
    int pairs = 0;
    for(int i = 0; i < dim; i++){
        for(int j = i + 1; j < dim; j++){
            if(arr[j] == targetSum - arr[i]){
                pairs++;
            }
        }
    }

    return pairs;
}