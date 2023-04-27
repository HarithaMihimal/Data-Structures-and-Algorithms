
#include <iostream>
using namespace std;

struct node {
    int key;
    struct node *left, *right;
};

// Create a new node to the tree
node* createNewNode(int data){
    node* temp = new node();  //create new temp object from node()
    temp->key = data;  //assign the value to the new node
    temp->right = temp->left = NULL; // create null leafs
    return temp;
}

// Inorder traversal
void traverseInOrder(node *root) {
    if(root != NULL){
        traverseInOrder(root->left);  //traverse left side of the root
        cout << root->key << " "; //print key value
        traverseInOrder(root->right); //traverse right side of the root
    }
}

// Insert a node
node* insertNode(struct node* root, int key) {
    if(root == NULL){ //check is root is null
        return createNewNode(key);  //is root is null then create new node
    }
    if (root->key > key){ //check the key value is < current root value
        root->left = insertNode(root->left, key); // create new node left side of the tree
    } else{  // current root value <= key value
        root->right = insertNode(root->right, key); //create new node right side of the tree
    }
    return root;
}

// function to find the minimum value and it's root
node* minValueNode(struct node* node){
    struct node* current = node;  //asign the value
    while(current && current->left != NULL){  //check both are not equal to null
        current = current->left;
    }
    return current;
}

// Deleting a node
node* deleteNode(struct node* root, int key) {
    if(root == NULL){  //check the root is null
        return root;
    }
     if(root->key < key){ //check the value of current root is < key value
        root->right = deleteNode(root->right, key);
    }
    else if(root->key > key){  //check the value of current root is < key value
        root->left = deleteNode(root->left, key);
    }  else{
        if(root->left == NULL){
            node* temp = root->right; // store the value of right side of the root temporary
            free(root); //delete the root
            return temp;  //return the temporary stored value
        } else if(root->right == NULL){
            node* temp = root->left; // store the value of left side of the root temporary
            free(root); //free up the root
            return temp; //return the temporary stored value
        }
        node* temp = minValueNode(root->right);
        root->key = temp->key;
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}

// Driver code
int main() {
    struct node *root = NULL;

    int operation;
    int operand;
    cin >> operation;

    while (operation != -1) {
        switch(operation) {
            case 1: // insert
                cin >> operand;
                root = insertNode(root, operand);
                cin >> operation;
                break;
            case 2: // delete
                cin >> operand;
                root = deleteNode(root, operand);
                cin >> operation;
                break;
            default:
                cout << "Invalid Operator!\n";
                return 0;
        }
    }

    traverseInOrder(root);
}
