using namespace std;

#include <iostream>
#include <fstream>
#include <string>

bool fileExists(string filename);
bool getFileContent(string filename, string &content);

int main (int argc, char * argv[]){

    fstream fread, fwrite;
    string fcontent = "", tempContent;
    bool res;

    if(argc < 3){
        cout << "Too few arguments inserted" << endl;
    }
    else{

        for(int i = 1; i < argc - 1; i++){

            res = getFileContent(argv[i], tempContent);
            if(res){
                fcontent.append(tempContent);
            }else
                cout << "File: " << argv[i] << " does not exist" <<endl;
            

        }

        fwrite.open(argv[argc - 1], ios_base::app);
        fwrite << fcontent;

    }

}


bool fileExists(string filename){

    bool ret;
    fstream fread;

    fread.open(filename, ios_base::in);
    
    if(fread){
        ret = true;
    }
    else
        ret = false;

    fread.close();

    return ret;

}

bool getFileContent(string filename, string &content){

    string tempContent;
    fstream fread;
    bool ret = false;
    
    content = "";

    if(fileExists(filename)){

        fread.open(filename, ios_base::in);
        while(fread){

            getline(fread, tempContent);
            if(fread)
                content.append(tempContent);

        }
        content.append(" ");
        ret = true;
    }

    return ret;
}