using namespace std;

#include <iostream>

int main ()
{
    // space allocated for types
    /*cout << sizeof(unsigned int) << endl;
    cout << sizeof(int) << endl;
    cout << sizeof(unsigned short) << endl;
    cout << sizeof(short) << endl;
    cout << sizeof(unsigned long) << endl;
    cout << sizeof(long) << endl;
*/

    //2-complement numbers --> first bit is sign 
    short smallest_num = 0b1000'0000'0000'0000;
    short biggest_num = ~smallest_num;

    unsigned short biggest_unsigned = 0b1111'1111'1111'1111;
    unsigned short smallest_unsigned = ~biggest_unsigned;
   
    cout << hex << smallest_num << endl;
    cout <<  biggest_num << endl;

    cout << dec<< smallest_unsigned << endl;
    cout <<  biggest_unsigned << endl;
	
    return 0;
}