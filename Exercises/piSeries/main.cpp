using namespace std;

#include <iomanip>
#include <iostream>
#include <cmath>
#include <cfloat>

long double computeSeries(unsigned int n);
bool checkDoubleLimits(long double num);

int main ()
{
    unsigned int n;
    long double res, piApprox;

    cout << "Insert an integer number representing the precision of the series to compute" << endl;
    cin >> n;

    if(n >= 1){

        res = computeSeries(n);
        cout << "Series with " << n << " precision: " <<setprecision(20) << fixed <<res << endl;
        piApprox = sqrt(res * 6);
        cout << "Approximation of Pi: " << piApprox;

    }else
        cout << "n must be at least one!";

    return 0;
}

long double computeSeries(unsigned int n){
    
    long double sum = 0;
    
    for(long i = 1; i <= n; i++){

        sum += double(1) / double(powf32x(i,2));
    }

    return sum;
}

bool checkDoubleLimits(long double num){
    return num >= LDBL_MIN && num <= LDBL_MAX;
}