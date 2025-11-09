using namespace std;

#include <iostream>
#include <cstdlib>

void rollTenDices(unsigned int &oneCounter);

int main ()
{
    unsigned int oneCounter = 0;
    int userGuess;
    
    rollTenDices(oneCounter);

    cout << "I rolled a 6-faces dice ten times, try to guess how many times a 1 occured" << endl;
    cin >> userGuess;
    if(userGuess == oneCounter){
        cout << "Congrats!, a 1 occured exactly " << userGuess << " times!";
    }else{
        cout << "Unfortunately, a 1 occured " << oneCounter << " times!";
    }


	return 0;
}

void rollTenDices(unsigned int &oneCounter){

    srand(time(NULL));
    int diceRoll = 0;

    for(int i = 0; i < 10; i++){
        diceRoll = rand() % 6 + 1;
        if(diceRoll == 1){
            oneCounter++;
        }
    }
}