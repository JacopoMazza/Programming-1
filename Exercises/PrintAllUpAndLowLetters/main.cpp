using namespace std;

#include <iostream>

int main ()
{
    //unsigned short range = 'z' - 'a';

    //lowercase letters
    for(unsigned int i = 'a'; i <= 'z'; i++){

        cout << char(i) << endl;
    }

    //uppercase letters
    for(unsigned int i = 'A'; i <= 'Z'; i++){
        cout << char(i) << endl;
    }
}