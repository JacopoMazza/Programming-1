using namespace std;

#include <iostream>

int main ()
{
    unsigned int a = 0, b = 0;

    //c = a && b;
    //cout << c << endl;


    //And Truth Table
    cout << "And Truth Table:" << endl;

    //0 & 0
    cout << a << " & " << b << " : " << (a && b) << endl;

    //0 & 1
    b = 1;
    cout << a << " & " << b << " : " << (a && b) << endl;

    //1 & 0
    a = 1;
    b = 0;
    cout << a << " & " << b << " : " << (a && b) << endl;

    //1 & 1
    b = 1;
    cout << a << " & " << b << " : " << (a && b) << endl;
  
	return 0;
}