using namespace std;

#include <iostream>
#include <iomanip>

int main ()
{
    float price = 1237.78f, vat = 34.76f, custPrice = 0.0f;


    custPrice = price + ((price * vat)/100.0);


    //use 5 decimal digits
    cout << "Price: " << price << endl;
    cout << "Vat: " << vat << endl;
    cout << "Customer Price: " << setprecision(5) << fixed << custPrice << endl;

	return 0;
}
