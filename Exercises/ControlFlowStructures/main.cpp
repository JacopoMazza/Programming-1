using namespace std;

#include <iostream>

int main ()
{
    short a = 10, b= 25;
    
    //collapsed conditional form
    short res= a > b? a: b;
    cout << res << endl;

    //if-then conditional form
    if(a >= b){
        cout << "a is greater than b" << endl;
    }
    else{
        cout << "b is greater than a" << endl;
    }
	
    return 0;
}