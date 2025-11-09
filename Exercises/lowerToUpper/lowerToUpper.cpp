using namespace std;

#include <iostream>
#include <cmath>

int main ()
{
    char phrase;
    char nextInBuffer;

    cout << "Insert the phrase you want to convert to lower-case letters, type ! to end the phrase, only uppercase letters will be counted" << endl;
    cin >> phrase;
    const unsigned short conversionRate = abs('a' - 'A');

    do{
        //Check if input is an uppercase letter
        if(phrase >= 64 && phrase <= 90){
            
            cout << char((phrase + conversionRate))<< endl;
        }
        
        //check if buffer is not ended
        nextInBuffer = cin.peek();
        if(nextInBuffer != '\n'){
            cin >> phrase;
        }else
            break;
        
        


    }
    while(phrase != '!');




    return 0;
}