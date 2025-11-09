#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char * argv[]) {

    fstream input, output;

    if (argc != 3) {
        cout << "Usage: ./a.out <inputFile> <outputFile>" << endl;
    }
    else {

        char currentCharacter;
        bool makeUppercase = true;

        input.open(argv[1], ios::in);
        output.open(argv[2], ios::out);

        if (input.fail()) {
            cout << "The file does not exist!" << endl;
        }
        else {
            input >> noskipws;

            while (input >> currentCharacter) {
                if (makeUppercase && 
                    currentCharacter >= 'a' && 
                    currentCharacter <= 'z') {
                    
                    currentCharacter += ('A' - 'a');
                    makeUppercase = false;
                }
                else if (currentCharacter == '.' || 
                         currentCharacter == '!' || 
                         currentCharacter == '?') {
                    makeUppercase = true;
                }

                output << currentCharacter;
            }

            input.close();
            output.close();
        }
    }

    return 0;
}