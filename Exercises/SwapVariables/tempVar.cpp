using namespace std;

#include <iostream>

int main ()
{
    int a = 1, b = 3, temp = 0, c = 6, d = 7;
    char c1 = 's', c2 = 'u';



    //swap variables
    cout << "Original variables a: " << a << " b: " << b << endl;

    temp = a;
    a = b;
    b = temp;

    cout << "Swapped variables a: " << a << " b: " << b << endl;

    //without temp var
    cout << "Original variables c: " << c << " d: " << d << endl;

    c+= d;
    d = c - d;
    c = c - d;

    cout << "Swapped variables c: " << c << " d: " << d << endl;

    //char test
    cout << "Original variables c: " << c1 << " d: " << c2 << endl;

    c1+= c2;
    c2 = c1 - c2;
    c1 = c1 - c2;

    cout << "Swapped variables c: " << c1 << " d: " << c2 << endl;


    
	return 0;

}
