#include <iostream>
#include <chrono>
using namespace std;

class Create_Node {
public:
    int Data;
    Create_Node* next;

    explicit Create_Node(int x) {
        Data = x;
        next = nullptr;
    }
};

class Stack {
private:
    Create_Node* top;

public:
    Stack() {
        top = nullptr;
    }

    void push(int x) {
        auto* newNode = new Create_Node(x);
        newNode->next = top;
        top = newNode;
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack underflow\n";
            return;
        }
        Create_Node* temp = top;
        top = top->next;
        delete temp;
    }

    int stackTop() {
        if (isEmpty()) {
            cout << "stack is empty\n";
            return 0;
        }
        return top->Data;
    }

    bool isEmpty() {
        return top == nullptr;
    }

    void display(){
        if(top !=nullptr){
            Create_Node* temp = top;
            while(temp != nullptr){
                cout<<temp->Data<<" ";
                temp = temp->next;
            }
            cout<<"\n";
        }
    }

};

int main() {
    Stack s;
    auto start = chrono::high_resolution_clock::now();
    s.push(8);
    s.push(10);
    s.push(5);
    s.push(11);
    s.push(15);
    s.push(23);
    s.push(6);
    s.push(18);
    s.push(20);
    s.push(17);
    s.display();
    int i=0;
    while (i<5){
        s.pop();
        i++;
    }
    s.display();
    s.push(4);
    s.push(30);
    s.push(3);
    s.push(1);
    s.display();
    auto end=chrono::high_resolution_clock::now();
    auto duration=chrono::duration_cast<chrono::microseconds>(end-start);
    cout<<"Time taken : "<<duration.count()<<" microseconds"<<endl;
    return 0;
}
