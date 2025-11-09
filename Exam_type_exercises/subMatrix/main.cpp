using namespace std;

#include <iostream>
#include <string>
#include <limits>
#include <iomanip>
#include <fstream>
#include <cstdlib>

void fillMatrix(int** mat,int row, int colums);
void printMatrix(int **mat, int rows, int columns);
int** createMatrix(int rows, int columns);
void printSubMatrix(int** mat, int rows, int columns, int startRow, int startCol, int subMatRows, int subMatCols);

int main(){
    
    srand(time(NULL));

    int dimensions[2];
    cout << "Insert dimensions of the matrix" << endl;

    for(int i = 0; i < 2; i++){
    
     do
     {
        cin >> dimensions[i];
     } while (cin.fail());
     
    }

    int** mat = createMatrix(dimensions[0], dimensions[1]);
    fillMatrix(mat, dimensions[0], dimensions[1]);
    printMatrix(mat, dimensions[0], dimensions[1]);

    int startingPos[2] = {};
    int subMatDims[2] = {};
    
    cout << "Insert starting position (row, column)" << endl;
    for(int i = 0; i < 2; i++){
        do
        {
            cin >> startingPos[i];
        } while (cin.fail());
    }

    cout << "Insert sub matrix dimension (rows, columns)" << endl;
    for(int i = 0; i < 2; i++){
        do
        {
            cin >> subMatDims[i];
        } while (cin.fail());
    }

    if(startingPos[0] >= 1 && startingPos[0] <= dimensions[0] && startingPos[1] >= 1 && startingPos[1] <= dimensions[1]){
        cout << "Requested sub-Matrix:"<< endl;
        printSubMatrix(mat, dimensions[0], dimensions[1], startingPos[0] - 1, startingPos[1] - 1, subMatDims[0], subMatDims[1]);

    }
    else{
        cout << "Invalid Starting Point" << endl;
    }
    
    return 0;

}

void fillMatrix(int** mat,int rows, int columns){
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < columns; j++){
            mat[i][j] = rand() % 10;
        }
    }
}

void printMatrix(int **mat, int rows, int columns){
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < columns; j++){
                cout << mat[i][j] << " ";
            }
            cout << endl;
        }
}

int** createMatrix(int rows, int columns){
    
    int** mat = new int*[rows];
    for(int i = 0; i < rows; i++){
        mat[i] = new int[columns];
    }

    return mat;
}

void printSubMatrix(int** mat, int rows, int columns, int startRow, int startCol, int subMatRows, int subMatCols){
    if(startRow + subMatRows  > rows){
        subMatRows = rows - startRow;
    }
    
    if(startCol + subMatCols  > columns){
        subMatCols = columns - startCol;
    }

    for(int i = startRow; i < startRow + subMatRows; i++){
        for(int j = startCol; j < startCol + subMatCols; j++){
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}