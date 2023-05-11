#include <iostream>
#include "linkedlist.cpp"
using namespace std;

struct HashTable{ // Define a struct for the hash table

    int MAX_LENGTH = 4;
    int MAX_CHAIN_LENGTH = 2;
    LinkedList * password = new LinkedList[MAX_LENGTH];     // Create an array of linked lists to hold passwords
    bool isFull(){
        bool full = true;
        int count = 0;
        for (int i = 0; i < MAX_LENGTH; i++){         // Loop through all slots in the array and check if the head of the linked list is NULL

            if(password[i].head == NULL){
                full = false;
            }
        }
        return full;
    }
    int hashfunc(string user_name){      // Hash function to convert user name to a slot in the array

        int sum = 0;
        int hash = 0;
        // Loop through each character in the user name and add its ASCII value to a total sum

        for(int i = 0;i< user_name.length(); i++){
            sum += int(user_name[i]);

        }
        hash = sum % MAX_LENGTH;  // Use modulus operator to map the sum to a slot in the array

        return hash;
    }
    bool is_slot_empty(int hash){  // Check if a slot in the array is empty
        bool empty;
        if(password[hash].head==NULL){   // If the head of the linked list at this slot is NULL, the slot is empty
            empty = true;
        }
        else{
            empty=false;
        }
        return empty;
    }
    void insert(string user_name,string user_password){  // Insert a new user name and password into the hash table
        int hash;
        bool empty;
        hash = hashfunc(user_name);  // Hash the user name to get its slot in the array
        empty = is_slot_empty(hash); // Check if the slot is already occupied
        if(password[hash].length<MAX_CHAIN_LENGTH){
            password[hash].insert(user_name.data(),user_password.data());

        }
        else{
            cout<<"Linked List reached MAX CAP!\n";
        }
    }
    // Print the full hash table
    void print_hashtable(){
        cout<<endl;
        for(int i=0;i<MAX_LENGTH;i++){
            cout<<"["<<i<<"]-->";
            password[i].print_list();
        }
    }
    void hash_lookup(string user_name){  // Look up a user's password by their user name
        int hash;
        bool empty;
        hash = hashfunc(user_name); // Hash the user name to get its slot in the array
        empty = is_slot_empty(hash);         // Check if the slot is empty

        if(empty){   // If the slot is empty, the user name was not found in the hash table
            cout<<"User name not found!\n";

        }
        else{
            password[hash].search(user_name);  // Call the linked list's search function to find the user's password
        }
    }

};

int main(){
    HashTable * hashtbl = new HashTable;
    cout<< hashtbl->isFull()<<"\n";
    int command=0;
    string user_name;
    string password;
    while (command!=-1){
        /* code */
        cout << "\nType command: ";
        cin >> command;
        switch (command){
            case 1:
                /* insert the new item*/
                cout << "Enter user name: ";
                cin >> user_name;
                cout << "Enter password to be saved: ";
                cin >> password;
                hashtbl->insert(user_name,password);
                break;
            case 2:
                /* hash lookup password*/
                cout << "Enter user name to look up password:";
                cin >> user_name;
                hashtbl->hash_lookup(user_name);
                break;
            case 3:
                hashtbl->print_hashtable();
                break;
            case -1:
                /* hash lookup password*/
                hashtbl->print_hashtable();
                cout << "Exiting...\n";
                break;

        }

    }
    return 0;
}
