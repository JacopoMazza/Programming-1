using namespace std;

#include <iostream>

long long factorialRec(int num);


int main ()
{

    int num;

    cout << "Insert the factorial you want to compute" << endl;
    cin >> num;

    cout << num << "! = " << factorialRec(num) << endl;

	return 0;
}


long long factorialRec(int num){

    if(num == 0 || num == 1){

        return 1;
    }else{
        
        return num * factorialRec(num - 1);

    }

}