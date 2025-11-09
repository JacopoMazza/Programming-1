using namespace std;

#include <iostream>
#include <string>
#include <limits>
#include <iomanip>
#include <fstream>
#include "queue.h"

void fillImgArr(string filename, int arr[], int dim);
void printArray(int arr[], int dim);
string arrToPPM3(int arr[], int dim, string ppm3Start, int width);
string getFirstNLinesFromFile(string filename, int n);
void rgb_rotate(int imgArr[], int dim);
void rgb_swap_elements(int &r, int &g, int &b);
void grayscale(int imgArr[], int dim);
void compute_grayscale(int &r, int &g, int &b);
void saturate(int imgArr[], int dim, float saturation_perc, int colorToSaturate);
void printToFile(string filename, string content);

int main(int argc, char * argv[]){
    
    string num;
    fstream fread, fwrite;
    string width, height, filename = "ex.jpg.ppm";

    //IMAGE INITIALIZATION
    fread.open(filename, ios_base::in);
    fread.ignore(100, '\n');
    fread >> width;
    fread >> height;
    fread.close();
    string ppm3Start = getFirstNLinesFromFile(filename, 3);
    int dim = stoi(width) * stoi(height) * 3;
    int * imgArr = new int[dim]; //array representing image pixel
    
    //USE QUEUE LIBRARY TO IMPLEMENT A QUEUE FOR THE COMMAND FROM COMMAND LINE THE REST OF THE FUNCTIONS ARE READY

    queue_node* start = NULL;
    if(argc != 1){
        
        //FILL THE QUEUE WITH COMMANDS
        for(int i = 1; i < argc; i++){
            enqueue(start, argv[i]);
        }
        
        //FILL IMAGE
        fillImgArr(filename, imgArr, dim);
        string ppm3Content;

        string command = dequeue(start);

        if (command.compare("--identity") == 0)
        {
            ppm3Content = arrToPPM3(imgArr, dim, ppm3Start, stoi(width)*3);
            printToFile("identityOutput.ppm",ppm3Content);

        }
        else if (command.compare("--rgb-rotate") == 0)
        {
            rgb_rotate(imgArr, dim);
            ppm3Content = arrToPPM3(imgArr, dim, ppm3Start, stoi(width)*3);
            printToFile("rgb-rotate_output.ppm",ppm3Content);

        }
        else if (command.compare("--redder") == 0)
        {
            //REDDER
            if(start){
                
                string saturation_perc = dequeue(start);
                try
                {
                    float perc = stof(saturation_perc);
                    saturate(imgArr, dim, perc, 1);
                    ppm3Content = arrToPPM3(imgArr, dim, ppm3Start, stoi(width)*3);
                    printToFile("redder_output.ppm", ppm3Content);
                }
                catch(invalid_argument)
                {
                    cout << "--redder needs a float value afterwards" << endl;
                }
                
            }
            else
                cout << "--redder needs the percentage value of saturation" << endl;

        }
        else if (command.compare("--greener") == 0)
        {
            if(start){
                
                string saturation_perc = dequeue(start);
                try
                {
                    float perc = stof(saturation_perc);
                    saturate(imgArr, dim, perc, 2);
                    ppm3Content = arrToPPM3(imgArr, dim, ppm3Start, stoi(width)*3);
                    printToFile("greener_output.ppm", ppm3Content);
                }
                catch(invalid_argument)
                {
                    cout << "--greener needs a float value afterwards" << endl;
                }
                
            }
            else
                cout << "--greener needs the percentage value of saturation" << endl;
            //GREENER
        }
        else if (command.compare("--bluer") == 0)
        {
            //BLUER
            if(start){
                
                string saturation_perc = dequeue(start);
                try
                {
                    float perc = stof(saturation_perc);
                    saturate(imgArr, dim, perc, 3);
                    ppm3Content = arrToPPM3(imgArr, dim, ppm3Start, stoi(width)*3);
                    printToFile("bluer_output.ppm", ppm3Content);
                }
                catch(invalid_argument)
                {
                    cout << "--bluer needs a float value afterwards" << endl;
                }
                
            }
            else
                cout << "--bluer needs the percentage value of saturation" << endl;
        }
        else
            cout << "Command: [ " << command << " ] not available" << endl;
    }
    else
    {
        cout << "The program needs at least one command!" << endl;
        cout << "Available commands: [--identity, --rgb-rotate, --redder, --greener, --bluer]" << endl;
    }

    return 0;
}



void fillImgArr(string filename, int arr[], int dim){
    
    fstream fread;
    string value;
    
    fread.open(filename, ios_base::in);
    fread.ignore(100, '\n');
    fread.ignore(100, '\n');
    fread.ignore(100, '\n');

    for(int i = 0; i < dim; i++){
        
        fread >> value;
        arr[i] = stoi(value);
    }
    
    fread.close();

}

void printArray(int arr[], int dim){
    for(int i = 0; i < dim; i++){

        if(i == 0){
            cout << "[ " << arr[i] << ", ";
        }
        else if(i == (dim - 1)){
            cout << arr[i] << " ]" << endl;
        }
        else
            cout << arr[i] << ", ";
    }
}

string getFirstNLinesFromFile(string filename, int n){
    
    fstream fread;
    string res,content;
    
    fread.open(filename, ios_base::in);
    //get first N lines from file filename
    for(int i = 0; i < n ; i++){
        
        getline(fread, content);
        res += string(content) + "\n";
    }

    fread.close();

    return res;

}

string arrToPPM3(int arr[], int dim, string ppm3Start, int width){

    string res = ppm3Start;

    for(int i = 0; i < dim; i++){

        res += to_string(arr[i]);
        //if i is multiple of width, add newline
        if((i + 1) % width == 0){
            res += "\n";
        }
        else
            res += " ";
    }

    return res;

}

void rgb_rotate(int imgArr[], int dim){

    for (int i = 0; i < dim; i += 3)
    {
        rgb_swap_elements(imgArr[i], imgArr[i + 1], imgArr[i + 2]);
    }
    
}

//r --> g, g --> b, b --> r
void rgb_swap_elements(int &r, int &g, int &b){

    int temp1;

    temp1 = r;
    r = g;
    g = b;
    b = temp1;
}

void grayscale(int imgArr[], int dim){

    for (int i = 0; i < dim; i += 3)
    {
        compute_grayscale(imgArr[i], imgArr[i + 1], imgArr[i + 2]);
    }
}

void compute_grayscale(int &r, int &g, int &b){
    
    r = int(r * 0.2989);
    g = int(g * 0.5870);
    b = int(b * 0.1140);

}

// 1 --> saturate red, 2 --> saturate green, 3 --> saturate blue
void saturate(int imgArr[], int dim, float saturation_perc, int colorToSaturate){

    int newColorValue = 0;

    for (int i = colorToSaturate - 1; i < dim; i += 3)
    {
        newColorValue = int(imgArr[i] * (1 + saturation_perc));
        if(newColorValue <= 255){
            imgArr[i] = newColorValue;
        }
        else
            imgArr[i] = 255;

    }
    
}

void printToFile(string filename, string content){

    fstream fwrite;
    fwrite.open(filename, ios_base::out);
    fwrite << content;
    fwrite.close();
}