
#include <cstring>
#include <string>
#include <iostream>
using namespace std;


struct HashTable{
    int MAX_LENGTH = 4;
    string * password = new string[MAX_LENGTH];

    void intialize_hashtable(){
        for (int i = 0; i < 4; i++){
            password[i].clear();
        }
    }
    bool isFull(){
        bool full = true;
        int count = 0;
        for (int i = 0; i < MAX_LENGTH; i++){
            if(password[i].empty()){
                full = false;
            }
        }
        return full;
    }



    int hashfunc(string user_name){
        int sum = 0; // initialize sum to 0
        int hash = 0; // initialize hash to 0
        for (int i = 0; i < user_name.length(); i++){ // loop through each character in the string
            sum += (int)user_name[i]; // add the ASCII value of the character to the sum
        }
        hash = sum % MAX_LENGTH; // compute the hash value by taking the sum modulo the maximum length of the hashtable
        return hash; // return the computed hash value
    }


    bool is_slot_empty(int hash){
        // Check if the string at the specified index is empty
        bool empty = password[hash].empty();
        return empty;
    }


    void insert(string user_name,string user_password){
        bool empty;
        int hash;
        hash = hashfunc(user_name);  // Compute the hash value for the given user_name
        empty = is_slot_empty(hash);   // Check if the slot at the computed hash is empty
        if(!empty){ // If the slot is not empty, print an error message indicating that the hashtable is full
            cout << "Hashtable is overflow. you could not be added anymore.\n";

        }
        else{  // Otherwise, add the user_password to the password array at the computed hash
            password[hash] = std::move(user_password);
            cout << "User added successfully\n";
        }


    }


    void hash_lookup(string user_name){
        int hash;
        bool empty;

        hash = hashfunc(user_name);  // Compute the hash value for the given user_name

        empty = is_slot_empty(hash); // Check if the slot at the computed hash is empty
        if(empty){
            cout<<"Not founded error"<<endl;
        }
        else{
            cout << "Password for user " << user_name << ": " << password[hash] << "\n";

        }


    }

    void delete_item(string user_name){
        int hash;
        bool empty;
        hash = hashfunc(user_name);  // Compute the hash value for the given user_name
        empty = is_slot_empty(hash);  // Check if the slot at the computed hash is empty
        if(empty){
            cout<<"No item found\n";
        }
        else{
            password[hash].clear(); //clear password value using crear() function
            cout<<"User deleted\n";
        }

    }
    void print_hashtable(){
        cout<<endl;
        // Loop through all possible indices in the hash table
        for(int i=0;i<MAX_LENGTH;i++){
            // Print the index followed by the corresponding value in the hash table
            cout<<"[ "<<i<<" ] --> "<<password[i]<<"\n";
        }
    }

};

int main(){
    HashTable * hashtbl = new HashTable;
    hashtbl->intialize_hashtable();
    cout<< hashtbl->isFull()<<"\n";

    int command;
    string user_name;
    string password;
    cout<<"========Command Menu=========="<<endl;

    cout << "1. Insert new password\n";
    cout  << "2. Delete password\n";
    cout  << "3. Lookup password\n";
    cout  << "4. Print hashtable\n";
    cout  << "-1. Exit\n";
    while (command!=-1){
        /* code */
        cout <<"Type command : ";
        cin >> command;
        switch (command){
            case 1:
                //insert the new item
                cout<<"Enter user name:\t";
                cin >> user_name;
                cout<<"Enter password to be saved: ";
                cin >> password;
                hashtbl->insert(user_name,password);
                break;
            case 2:
                /* delete item */
                cout << "Enter item to be deleted: ";
                cin >> user_name;
                hashtbl->delete_item(user_name);
                break;
            case 3:
                /* hash lookup password*/
                cout << "\nEnter user name to look up password: ";
                cin >> user_name;
                hashtbl->hash_lookup(user_name);
                break;
            case 4:
                hashtbl->print_hashtable();
                break;
            case -1:
                hashtbl->intialize_hashtable();
                /* hash lookup password*/
                cout << "\nExiting...\n";
                break;
        }

    }
    return 0;
}
