#include <iostream>
#include <cstdlib>

using namespace std;

void initializeArray(int array[], int dim);
void printArray(int array[], int dim);
bool patternMatching(int pattern[], int patternDim, int text[], int textDim);

int main() {

    int patternDim = 3;
    int textDim = 20;

    int pattern[patternDim];
    int text[textDim];

    srand(time(NULL));

    initializeArray(pattern, patternDim);
    initializeArray(text, textDim);

    printArray(pattern, patternDim);
    printArray(text, textDim);


    if (patternMatching(pattern, patternDim, text, textDim)) {
        cout << "The pattern is contained in the text" << endl;
    }
    else {
        cout << "The pattern is not contained in the text" << endl;
    }

    return 0;
}

void initializeArray(int array[], int dim) {
    for (int i = 0 ; i < dim ; i++) {
        array[i] = rand() % 10;
    }
}

void printArray(int array[], int dim) {
    for (int i = 0 ; i < dim ; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}

bool patternMatching(int pattern[], int patternDim, int text[], int textDim) {

    bool match = false;

    for (int indexText = 0 ; indexText < (textDim-patternDim) && !match ; indexText++) {
        for (int indexPattern = 0; indexPattern < patternDim && 
            text[indexText+indexPattern] == pattern[indexPattern] ; 
            indexPattern++) {
            if (indexPattern == patternDim - 1) {
                match = true;
            }
        }
    }

    return match;
}









