using namespace std;

#include <iostream>

int divisionRecursion(int numerator, int denominator, int &remainder);

int main ()
{
    int num = 5, den = 3, rem = 0, quotient;
	
    quotient = divisionRecursion(num, den, rem);
    cout << num << " / " << den << " = " << quotient << " ,rem " << rem << endl;

    
    return 0;
}

int divisionRecursion(int numerator, int denominator, int &remainder){
    if(numerator == 0){

        remainder = 0;
        return 0;

    }else if(numerator < denominator){
        
        remainder = numerator;
        return 0;

    }else{
        return 1 + divisionRecursion(numerator - denominator, denominator, remainder);
    }
}
