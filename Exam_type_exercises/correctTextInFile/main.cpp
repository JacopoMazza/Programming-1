using namespace std;

#include <iostream>
#include <string>
#include <limits>
#include <iomanip>
#include <fstream>
#include <cstdlib>

string getFileContent(string filename);
void correctFileContent(string &content);
void toUpper(char &ch);

int main(int argc, char* argv[]){
    
    string content;
    fstream fwrite;


    /*if(argc >= 3){
        
        content = getFileContent(argv[1]);
        correctFileContent(content);
    
        fwrite.open(argv[2], ios_base::out);
        fwrite << content;

    }*/

    content = getFileContent("input.txt");
    correctFileContent(content);

    fwrite.open("output.txt", ios_base::out);
    fwrite << content;

    return 0;
}

string getFileContent(string filename){

    fstream fread;
    string content = "", newLine;

    fread.open(filename, ios_base::in);

    while(!fread.eof()){

        getline(fread,newLine);
        content += newLine +"\n";
        
    }

    fread.close();
    return content;

}

void correctFileContent(string &content){
    int len = content.length(), j = 0;
    bool found = false;

    for(int i = 0; i < len; i++){
        
        if(i == 0 && content[i] >= 'a' && content[i] <= 'z'){
            toUpper(content[i]);
        }

        if(content[i] == '.' || content[i] == '!' || content[i] == '?'){
            j = i + 1;
            found = false;
            while(j < len && !found){
                if((content[j] >= 'A' && content[j] <= 'Z') || (content[j] >= 'a' && content[j] <= 'z')){
                    found = true;
                    break;
                }
                j++;
            }

            if(found && (content[j] >= 'a' && content[j] <= 'z')){
                toUpper(content[j]);
            }
        }


    }
}


void toUpper(char &ch){
    
    int change = 'A' - 'a';

    ch = ch + change;
}
