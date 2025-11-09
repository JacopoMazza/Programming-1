using namespace std;

#include <iostream>
#include <string>
#include <limits>
#include <iomanip>
#include <algorithm>



struct contact {

    string name;
    string surname;
    string phone;
    string email;
};
int contactNum = 0;


void addContact(contact *contacts[]);
void insertContactInfo(contact *cont);
void printContactList(contact *contacts[]);
void printContact(contact *cont, int index);
void deleteContact(contact *contacts[], int contPos, int maxNumConts);
int  getContsToSwap(contact *contacts[], int nextContPos, int maxNumConts);
void swapConts(contact *contacts[], int swapsNum, int startIndex);
void menu();
contact* copyContact(contact *contacts[], int contactPos);
void editMenu();
void editContact(contact *copy, int field, string newValue);
int edit(contact *contacts[]);


int main(){


    int dim = 10;
    contact *contacts[dim] = {NULL};
    int choice, editRes;

    bool exit = false;

    while(!exit){

        menu();

        cin >> choice;

        if(cin.fail()){
            cout << "Incorrect input!" << endl;
            cout << "Exiting main Menu..." << endl << endl;
            break;
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch(choice){

            case 1:

                if (contactNum == dim){
                    cout << "Contact List is already Full!" << endl << endl;
                    break;
                }
                        
                addContact(contacts);
                
                break;

            case 2:


                if (contactNum == 0){
                    cout << "You need at least one contact to perform this operation" << endl<< endl;
                    break;
                }

                int contToDelete;
                cout << "Insert the number of the contact to be deleted" <<endl;
                cin >> contToDelete;
                    
                if(cin.fail()){
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "Incorrect input" << endl << endl;
                        break;
                }

                if(contToDelete > contactNum){
                        cout << "Inserted contact does not exist" << endl << endl;
                        break;
                }

                deleteContact(contacts, contToDelete - 1, dim);
                break;

            case 3:
                    
                if(contactNum == 0){
                    cout << "The contact list is empty!" << endl << endl;
                    break;
                }

                printContactList(contacts);

                break;

            
            case 4:

                editRes = edit(contacts);

                if(editRes == -1){
                    cout << "The contact list is empty!, cannot perform this operation" << endl << endl;
                    break;
                }

                else if (editRes == 1)
                {
                    cout << "Incorrect input" << endl << endl;
                    break;
                }

                else if (editRes == 2)
                {
                    cout << "Inserted contact does not exist" << endl << endl;
                    break;
                }    


                break;
            
            
            
            default:
                cout << "Exiting main Menu..." << endl;
                exit = true;


        }
    }

    return 0;

}


//FUNCTIONS


void addContact(contact *contacts[]){

    contact *cont = new contact;

    contacts[contactNum] = cont;
    insertContactInfo(contacts[contactNum]);
    contactNum++;

    cout << "Contact Added Successfully" << endl << endl;
}

void insertContactInfo(contact *cont){

    

    cout << "Insert Data of the contact" << endl;
    cout << "Insert Name" << endl;
    getline(cin, cont -> name );
    cout << "Insert Surname" << endl;
    getline(cin, cont -> surname );
    cout << "Insert Phone Number" << endl;
    getline(cin, cont -> phone );
    cout << "Insert email Address" << endl;
    getline(cin, cont -> email );
    
}

void printContact(contact *cont, int index){


    cout << endl;
    cout << "Contact " << index + 1 << endl;
    cout << "Name      :" << setw(25) << cont -> name << endl;
    cout << "Surname   :" << setw(25) << cont -> surname << endl;
    cout << "Email     :" << setw(25) << cont -> email<< endl;
    cout << "Phone     :" << setw(25) << cont -> phone << endl;
    cout << endl;

}

void printContactList(contact *contacts[]){

    int i = 0;
    while(contacts[i] != NULL && i < contactNum){
        printContact(contacts[i], i);
        i++;
    }
}

void deleteContact(contact *contacts[], int contPos, int maxNumConts){
    
    int swapsNum;
    
    delete contacts[contPos];
    contacts[contPos] = 0;
    contactNum --;
    
    swapsNum = getContsToSwap(contacts, contPos + 1, maxNumConts);
    swapConts(contacts, swapsNum, contPos);

    cout << "Contact deleted successfully!" << endl << endl;

}

//starts at item after the one deleted and checks how many non null items there are up to the end
int getContsToSwap(contact *contacts[], int nextContPos, int maxNumConts){
    int ret = 0;
    
    while(contacts[nextContPos] && nextContPos <= maxNumConts - 1){
        ret++;
        nextContPos++;
    }

    return ret;
}

//starts at deleted item an swaps for swapsNum times
void swapConts(contact *contacts[], int swapsNum, int startIndex){
    
    int i;

    for(i = startIndex; i < startIndex + swapsNum; i++){
        contacts[i] = contacts[i + 1];
    }

    contacts[i] = NULL;
}

void menu(){

    cout << "Choose the operation" << endl;
    cout << "1) Add Contact" <<endl;
    cout << "2) Delete Contact" <<endl;
    cout << "3) Print Contacts" <<endl;
    cout << "4) Edit Contact" <<endl;
    cout << "5) Exit" <<endl;
}

contact* copyContact(contact *contacts[], int contactPos){

    contact *copy = new contact;

    copy -> name = contacts[contactPos] -> name;
    copy -> surname = contacts[contactPos] -> surname;
    copy -> email = contacts[contactPos] -> email;
    copy -> phone = contacts[contactPos] -> phone;

    return copy;
}

void editMenu(){

    cout << "Choose the field to be edited" << endl;
    cout << "1) Name" <<endl;
    cout << "2) Surname" <<endl;
    cout << "3) Email" <<endl;
    cout << "4) Phone" <<endl;
    cout << "5) Exit" <<endl;
}

void editContact(contact *copy, int field, string newValue){

    switch (field)
    {
        case 1:
            copy -> name = newValue;
            break;
    
        case 2:
            copy -> surname = newValue;
            break;
        
        case 3:
            copy -> email = newValue;
            break;
        
        case 4:
            copy -> phone = newValue;
            break;
        
        default:
            break;
    }


}

/***********************************************
 * return values:
 * -1 -> contact list is empty
 * 1  -> incorrect input in number of contact
 * 2  -> contact does not exist
 * 0  -> correctly edited
 ************************************************/
int edit(contact *contacts[]){

    if(contactNum == 0){
        return -1;
    }

    cout << "Insert the number of the contact you want to edit" << endl;
    int contToEdit;
    cin >> contToEdit;
                    
    if(cin.fail()){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return 1;
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');       

    
    if(contToEdit <= 0 || contToEdit > contactNum){
        return 2;
    }     



    contact *copy = copyContact(contacts, contToEdit - 1);


    //Editing menu
    bool editExit = false;
    while(!editExit)
    {

        int editChoice;
        editMenu();
        cin >> editChoice;
                        
    
        while(cin.fail()){

            cout << "Input must be an integer number" << endl << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            editMenu();
            cin >> editChoice;
        }
        //when entering 123a, does not fail and keeps 'a' in buffer
        cin.ignore(numeric_limits<streamsize>::max(), '\n');                        
        
        if(editChoice == 1)
        {
            string newName;
            cout << "Insert the new name" << endl;
            getline(cin, newName);

            editContact(copy, editChoice, newName);
        }       
                            
        else if(editChoice == 2){

                                                            
            string newSurname;
            cout << "Insert the new surname" << endl;
            getline(cin, newSurname);

            editContact(copy, editChoice, newSurname);
        }
                        
                        
        else if (editChoice == 3){

            string newEmail;
            cout << "Insert the new email" << endl;
            getline(cin, newEmail);

            editContact(copy, editChoice, newEmail);
        }

        else if (editChoice == 4){
            
            string newPhone;
            cout << "Insert the new phone number" << endl;
            getline(cin, newPhone);

            editContact(copy, editChoice, newPhone);
        }
                        
        
        else{

            cout << "Exiting Edit..." << endl << endl;
            editExit = true;

        }


    }

    //swap edited contact with previous one
    contacts[contToEdit - 1] = copy;

    cout << "Edited Contact" << endl;
    printContact(contacts[contToEdit - 1], 1);

    return 0;

}