using namespace std;

#include <string>
#include <iostream>

int wordCounter(string str);

int main(){

    //char str[256];
    string str;

    cout << "Insert a string (maximum 256 chars) " << endl;
    getline(cin, str);

    
    cout << "Inserted string: " << str << endl;
    cout << "Number of Words: " << wordCounter(str) << endl;
    
    
    return 0;
}

int wordCounter(string str){

    int ret = 0;

    for(int i = 0; i < str.size(); i++){

        if(str[i] == ' '){
            ret++;
        }
    }

    return ret + 1;
}