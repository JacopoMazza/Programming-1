using namespace std;

#include <iostream>
#include <climits>


bool checkIntLimits(int num);
void revertNumber(int num);

int main ()
{
    int num;

    cout << "Insert a number to revert" << endl;
    cin >> num;

    if(checkIntLimits(num)){
        cout << "The reversion of the inserted number is: ";
        revertNumber(num);
    }else
        cout << "The inserted number is not in the range of the int32";

	return 0;
}


void revertNumber(int num){

    int leastSigDigit = 0;

    //iterate throug num, take leastSig digit, divide by 10 and repeat
    do{
        leastSigDigit = num % 10;
        cout << leastSigDigit;
        num /= 10;

    }while(num != 0);
}

