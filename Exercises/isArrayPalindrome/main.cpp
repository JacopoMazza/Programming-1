using namespace std;

#include <iostream>

bool isPalindrome(int arr[], int dim);

int main ()
{

    int dim1 = 5, dim2 = 6;
    int arr[dim1] = {1,2,3,2,1};
    int arr2[dim2] = {1,2,3,3,2,1};
  
  	cout << isPalindrome(arr, dim1) << endl;
    cout << isPalindrome(arr2, dim2) << endl;

	return 0;
}

bool isPalindrome(int arr[], int dim){

    int p1 = 0;
    int p2 = dim - 1;
    bool isPalindrome = true;

    while(p2 > p1){

        if(arr[p1] != arr[p2]){
            isPalindrome = false;
        }

        p2--;
        p1++;
    }

    return isPalindrome;
}