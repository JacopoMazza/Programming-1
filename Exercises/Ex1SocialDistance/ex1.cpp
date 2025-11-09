using namespace std;

#include <iostream>

int main ()
{
    int rad = 5;
    double pi = 3.1415;
    double area = 0;
    double circ = 0;

    area = pi*(rad^2);
    circ = 2*pi*rad;

    cout << "Radius: "<< rad << endl;
    cout << "Area: "<< area << endl;
    cout << "Circumference: "<< circ << endl;
  
	return 0;
}