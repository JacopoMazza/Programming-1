using namespace std;

#include <iostream>

long long sumOfFirstInt(int num);

int main ()
{

    int num;

    cout << "Insert the number of first integers you want to sum" << endl;
    cin >> num;

    cout << "Sum of first " << num << " Integers = " << sumOfFirstInt(num) << endl;

	return 0;
}

long long sumOfFirstInt(int num){

    if(num == 0){
        
        return 0;

    }else{

        return num + sumOfFirstInt(num - 1);
    }

}
