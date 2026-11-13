#include <iostream>
using namespace std;

struct Node {
    double value;
    Node* next;
};

struct Stack {
    Node* top = nullptr;  
    int size = 0;         
};

bool isEmpty(const Stack* s) {
    return s -> top == nullptr;
}

void push(Stack* s, double value) {
    Node* newNode = new Node{value, s -> top};  
    s -> top = newNode;                         
    s -> size++;
}

void pop(Stack* s) {
    if (isEmpty(s)) {
        cout << "error";
        return;
    }   
    Node* temp = s -> top;      
    s -> top = s -> top -> next;    
    delete temp;              
    s -> size--;
}
int size(const Stack* s) {
    return s -> size;
}
double top(const Stack* s) {
    if (isEmpty(s)) {
        cout << "error";  
        return 0.0;
    }
    return s -> top -> value;
}
void clear(Stack* s) {
    while (!isEmpty(s)) {
        pop(s);
    }
}