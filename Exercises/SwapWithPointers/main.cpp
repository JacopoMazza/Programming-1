using namespace std;

#include <iostream>

void swapVar(double *num1, double *num2);

int main ()
{
    double num1, num2;
    
    cout << "Insert two double values to swap" << endl;
    cin >> num1 >> num2;

    
    cout << num1 << "\t" << num2 << endl;
    swapVar(&num1,&num2);

    cout << "Swapped variables" << endl;
    cout << num1 << "\t" << num2 << endl;
	
    return 0;
}

void swapVar(double *num1, double *num2){
    double temp;

    temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}