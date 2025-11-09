using namespace std;

#include <iostream>
#include <cmath>
#include <iomanip>

long double computeHarmonic(int end);

int main ()
{

    int lim;
    long double res;

    cout << "Insert the limit of the harmonic series to compute" << endl;
    cin >> lim;

    //cout << (!cin.fail()) << endl;
    //cout << (lim >= 1) << endl;
    //cout << lim << endl;


    if(!cin.fail() && lim >= 1){

        res = computeHarmonic(lim);
        cout << "The harmonic series up to " << lim << " is: " << setprecision(10) << fixed << res << endl;

    }
    else{
        cin.clear();
        cout << "Invalid end number, it must be greater or equal than 1" << endl;
    }

  
  	
}


long double computeHarmonic(int end){

    if (end == 1){

        return 1.0;

    }else
        return (1.0 / double(end)) + computeHarmonic(end - 1);

}
