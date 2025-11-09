#include <iostream>
#include <cstring>
#include "queue_c_list.h"

using namespace std;


int main() {

    init();

    cout << "Insert: " << endl;
    cout << "- 'remove' to remove a person" << endl;
    cout << "- 'print' to see the queue" << endl;
    cout << "- 'exit' to exit" << endl;
    cout << "- a name to add a person " << endl;

    bool exit = false;
    char input[MAX_DIM];

    while (!exit) {
        
        cin >> input;

        if (strcmp(input, "remove") == 0) {
            char * firstT;
            if (first(firstT)) {
                dequeue();
                cout << " #we removed " << first << endl;
                delete[] firstT;
            } else {
                cout << " queue empty" <<  endl;
            }
        }
        else if (strcmp(input, "print") == 0) {
            cout << " #the queue contains these persons: " << endl;
            print();
        }
        else if (strcmp(input, "exit") == 0) {
            cout << "Program end" << endl;
            exit = true;
        }
        else {
            cout << " #we have inserted " << input << " in the queue" << endl;
            enqueue(input);
        }
    }

    deinit();

    return 0;
}
