using namespace std;
#include <iostream>
#include <iomanip>
#include <ctime>
#include <fstream>
#include <string>

bool isInsideArray(int A[], int s1, int n ){
   for( int i = 0; i < s1; i++) {
      if( A [ i ] == n ) {
         return true;   
      }
   }
   return false;
}

int* second_unique(int array1[],int s1, int &u1){
  //non optimized
  int j=0;
  int arrayU[s1]={};
  for(int i=0; i<s1; i++)
    {
      if (!isInsideArray(arrayU,s1, array1[i])){
          arrayU[j]=array1[i];
          j++;
      }
    }
  u1= j;
  int* arrayU2=new int[u1];
  for(int i=0; i<u1; i++){
    arrayU2[i]=arrayU[i];
  }
  return arrayU2;
}

void foruth_bubbleSort(int array1[],int s1){
  for(int i=0; i<s1; i++)
    {
        for(int j=i+1; j<s1; j++) { 
          if(array1[i]>array1[j])
            {
                int temp = array1[i];
                array1[i] = array1[j];
                array1[j] = temp;
            }
        }
    }
}

void third_count(int array1[], int &ctr, int s1, int sum){
  int s[s1]={}; int sd_index=0;
  int d[s1]={}; 
  ctr=0;
  for (int i = 0; i < s1; i++) 
    {
        for (int j = i + 1; j < s1; j++) 
        {
            if (array1[i] + array1[j] == sum) 
            {
              if ( (!isInsideArray(s,s1,array1[i])) && (!isInsideArray(d,s1,array1[j])) ){
                if ( (!isInsideArray(d,s1,array1[i])) && (!isInsideArray(s,s1,array1[j])) ){
                  cout << " \n " << array1[i] << "," << array1[j]; 
                  ctr++; 
                  s[sd_index]=array1[i];
                  d[sd_index]=array1[j];
                  sd_index++;
                }
              }
            }
        }
    }

}

// A quick way to split strings separated via spaces.
void line_tokenizer(int arrSint[], string row,int &count)
{
    char separator=' ';
    int i=0,j=0;
    string s="";
    while (i<row.length()) {
        if (row[i] != separator) {
            s += row[i]; 
        } else {
            arrSint[j]=s.length();
            j++;
            s.clear();
        }
        i++;
        if (i==row.length()-1){
          arrSint[j]=s.length();
          j++;
        }
    } 
    count=j;
}

void printArray(int array1[], int s1){
   for (int i = 0; i < s1; i++) 
      cout << array1[i] << " ";
}

bool first_readFile(string filePath, string arrayS[], int &sizeS){
    if (filePath=="")
      filePath="myFile.txt";
    ifstream file(filePath);
    if (!file.is_open()) {
        cerr << "Failed to open file: " << filePath << endl;
        return false;
    }

    // Read the file line by line into a string
    string line;
    int i=0;
    while (getline(file, line)) {
        cout << line << endl;
        arrayS[i]=line;
        i++;
    }
    sizeS=i;

    file.close();
    return true;
}

int main ()
{
  string arraySLines[100];
  int y=0;

  bool read=first_readFile("input.txt",arraySLines, y);

  if (read) {
    int a[100]={};
    int asize=0;
    int count=0;
   for(int i=0; i<y; i++){
       line_tokenizer(a,arraySLines[i],count);
      
      cout << "\n***** Y ="<< i << endl;
      ////
      int s1 = count;
      int sum = a[s1-1];
      int ctr = 0; 

      cout << "Original array: "; 
      printArray(a, s1);

      cout << "\nUnique elements in the array:";
      int* arrayU; 
      int u1=0;
      arrayU=second_unique(a,s1,u1);
      printArray(arrayU, u1); // Output the unique elements of the array
      
      cout << "\nArray pairs whose sum equal to " << sum <<": "; 
      third_count(a, ctr, s1, sum);
      cout << "\nNumber of pairs whose sum equals "<< sum << ": "; // Output label for count of pairs
      cout << ctr << endl; // Output the count of pairs

      cout << "Ordered array:";
      int arrayOrd[s1];
      for(int i=0; i<s1; i++){
          arrayOrd[i] = a[i];
        }
      foruth_bubbleSort(arrayOrd, s1);
      printArray(arrayOrd, s1);
      cout << endl; // Output the ordered array
      
      ////
      cout << endl;
    }
  }

  return 0; 

}