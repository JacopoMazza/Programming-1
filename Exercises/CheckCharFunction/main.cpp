using namespace std;

#include <iostream>

bool isLower(char c);
char toUpper(char lowerChar);
void printChar(char c);


int main ()
{

    char inputCh;

    cout << "Insert a lower-case character" << endl;
    cin >> inputCh;

    if(isLower(inputCh)){
        printChar(toUpper(inputCh));
    }else
        cout << "Inserted character is not a lowercase letter!" << endl;


	return 0;
}


bool isLower(char c){

    return (c >= 'a' && c <= 'z');
}

char toUpper(char lowerChar){
    //const unsigned short convRate = 'a' - 'A';
    char upperChar;

    upperChar = (lowerChar - 'a') + 'A';
    return upperChar;
}

void printChar(char c){

    cout << "Uppercase version of inserted char: " << c << endl;
}