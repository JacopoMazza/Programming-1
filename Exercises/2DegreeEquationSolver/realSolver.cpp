using namespace std;

#include <iostream>
#include <cmath>

int main ()
{
    int a,b,c;
    int delta = 0;
    float x1 = 0, x2 = 0;


    //ask for the coefficients
    cin >> a >> b >> c;

    cout << a << endl << b << endl << c << endl;
    
    //compute delta
    delta = pow(b,2) - (4*a*c);

    if(delta >= 0){
        x1 = (-b + sqrt(delta))/2*a;
        x2 = (-b - sqrt(delta))/2*a;

        cout << "The solution to your equations are: " << x1 << "," << x2<< endl;
    }
    else
        cout << "The proposed equation has not solution belonging to the real numbers";

    return 0;
}