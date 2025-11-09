using namespace std;

#include <iostream>

int divide(int num, int denom, int &rem);

int main ()
{
    int numerator, denominator, q, r;

    cout << "Insert two integers number representing the divident and the divisor" << endl;
    cin >> numerator >> denominator;

    q = divide(numerator, denominator, r);
    cout << numerator << " / " << denominator << endl;
    cout << "Quotient: " << q << "\t" << "Remainder: " << r << endl;


	return 0;
}

int divide(int num, int denom, int &rem){
    
    int q = 0;

    while(num >= denom){
        
        num -= denom;
        q++;
    }

    rem = num;
    return q;
}
