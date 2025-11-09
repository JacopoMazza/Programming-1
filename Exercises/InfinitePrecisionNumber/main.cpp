using namespace std;

#include <iostream>
#include <climits>
#include <cmath>


void IntToArray(int arr[], int dim, int num);
void printArr(int arr[], int dim);
void InitArr(int arr[], int dim);
int  getDigits(int arr[], int dim);
int  multiplyByPower10(int arr[], int dim, int exp);
void clearArr(int arr[], int clearingZone);
void Sum(int num1[], int num2[], int sum[], int dim1, int dim2);


int main ()
{

    int num = 6, dim = 100, mult_res, num2 = 3;
    int num1Arr[dim], num2Arr[dim], sum[dim];


    InitArr(num1Arr, dim);
    IntToArray(num1Arr, dim, num);
    printArr(num1Arr, dim);

    InitArr(num2Arr, dim);
    IntToArray(num2Arr, dim, num2);
    printArr(num2Arr, dim);

    mult_res = multiplyByPower10(num1Arr, dim, 2);
    if(!mult_res){

        printArr(num1Arr, dim);

    }

    Sum();



	return 0;
}


void IntToArray(int arr[], int dim, int num){

    int i = 0;

    while(num >= 1 && i < dim){
        
        arr[i] = num % 10;
        num = num / 10;
        i++;
    }

}

void printArr(int arr[], int dim){

    int digits;

    digits = getDigits(arr, dim);

    for(int i = digits - 1; i >= 0; i--){

        cout << arr[i];
    }

    cout << endl;

}

void InitArr(int arr[], int dim){

    for(int i = 0; i < dim; i++){
        arr[i] = 0;
    }

}

int getDigits(int arr[], int dim){

    int dig = 0, zeros = 0;

    while(arr[zeros] == 0){
        zeros++;
    }

    for(int i = zeros; i < dim; i++){

        if(arr[i] != 0){
            dig++;
        }

    }

    return dig + zeros;
}

/********************************************************** 
 * ret -> 0 OK, 1 destArr too small
 *
 * 
 * 
 * 
 * 
*************************************************************/
int multiplyByPower10(int arr[], int dim, int exp){

    int ret, digits;

    digits = getDigits(arr, dim);

    if(dim >= digits + exp){

        for(int i = digits - 1; i >= 0; i--){

            arr[i + exp] = arr[i];
        }

        clearArr(arr, exp);
        ret = 0;

    }else
        ret = 1;

    return ret;


}


void clearArr(int arr[], int clearingZone){

    for(int i = 0; i < clearingZone; i++){
        arr[i] = 0;
    }
}


void Sum(int num1[], int num2[], int sum[], int dim1, int dim2){

    int maxDigits, carry;

    maxDigits = max(getDigits(num1, dim1), getDigits(num2, dim2));

    for(int i = 0; i < maxDigits; i++){

        carry = (num1[i] + num2[i]) / 10;
        sum[i] = (num1[i] + num2[i] + carry) % 10; 

    }

    if(carry != 0){
        sum[maxDigits] = carry;
    }



}