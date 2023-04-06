#include <iostream>
#include <chrono>

using namespace std;

class Stack {
    int top;
    int *arr;

public:
    Stack(int size) {
        top = -1;
        arr = new int[size];
    }


    bool isFull() {
        return top ==sizeof (arr)/sizeof(int)- 1;
    }
    bool isEmpty() {
        return top == -1;
    }

    int stackTop() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return -1;
        }
        return arr[top];
    }

    int pop() {
        if (isEmpty()) {
            cout << "Stack Underflow\n";
            return -1;
        }
        return arr[top--];
    }
    void push(int val) {
        if(isFull()){
            cout<<"Stack overflow\n";
        }
        arr[++top] = val;
    }

    void display() {
        if (top >= 0) {
            for (int i = top; i>=0; i--) {
                cout << arr[i] << " ";
            }
            cout <<"\n";
        }
    }
};

int main() {
    Stack s(13);
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
