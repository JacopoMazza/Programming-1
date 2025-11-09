using namespace std;

#include <iostream>
#include <cmath>

int main ()
{
    int a,b;
    cout << "Insert two numbers representing the range of letters you want to print in the ASCII Table" << endl;
    cin >> a >> b;

    a = min(abs(a),abs(b));
    b = max(abs(a),abs(b));
    if( a >= 32 and b <= 127){
        for(int i = a; i <= b; i++){
            cout << char(i) << endl;
        }
    }else
        cout << "The range does not represent a correct ASCII range" << endl;
   

}