#include <iostream>
#include <cstdlib>

using namespace std;

int ** matrixInitialization(int rows, int cols);
void printMatrix(int ** matrix, int rows, int cols, int coordinateRow, int coordinateCol, int rowSubMatrix, int colsSubMatrix);
void deallocateMatrix(int ** matrix, int rows);

int main() {

    int rows, cols;
    cout << "Insert the number of rows: ";
    cin >> rows;
    cout << "Insert the number of cols: ";
    cin >> cols;

    srand(time(NULL));
    int ** matrix = matrixInitialization(rows, cols);
    printMatrix(matrix, rows, cols, 0, 0, rows, cols);

    int coordinateRow, coordinateCol;
    int rowSubMatrix, colsSubMatrix;
    cout << "Insert coordinates of the starting cell" << endl;
    cout << "Rwo: ";
    cin >> coordinateRow;
    cout << "Col: ";
    cin >> coordinateCol;

    cout << "Insert the number of rows of the submatrix: ";
    cin >> rowSubMatrix;
    cout << "Insert the number of cols of the submatrix: ";
    cin >> colsSubMatrix;

    printMatrix(matrix, rows, cols, 
        coordinateRow, coordinateCol, 
        rowSubMatrix, colsSubMatrix);

    deallocateMatrix(matrix, rows);

    return 0;
}


int ** matrixInitialization(int rows, int cols) {

    int ** matrix = new int*[rows];

    for (int row = 0; row < rows; row++) {
        matrix[row] = new int[cols];
        for (int col = 0; col < cols; col++) {
            matrix[row][col] = rand() % 10;
        }
    }

    return matrix;
}


void printMatrix(int ** matrix, int rows, int cols, 
    int coordinateRow, int coordinateCol, 
    int rowSubMatrix, int colsSubMatrix) {

        for (int row = coordinateRow; row < rows && (row-coordinateRow) < rowSubMatrix;  row++) {

            for (int col = coordinateCol;  col < cols && (col-coordinateCol) < colsSubMatrix; col++) {
                    cout << matrix[row][col] << " ";
                }

            cout << endl;
        }
    }


void deallocateMatrix(int ** matrix, int rows) {
    for (int i = 0; i < rows; i++) {
        delete[] matrix[i];
    }
    delete [] matrix;
}