#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;
};

class List {
private:
    Node* head;
    Node* tail;
public:
    List() {
        head = nullptr;
        tail = nullptr;
    }
    void push_back(int value) {
        Node* new_Node = new Node;
        new_Node->data = value;
        new_Node->next = nullptr;
        new_Node->prev = tail;
        if (head == nullptr) {
            head = new_Node;
            tail = new_Node;
            return;
        }
        tail->next = new_Node;
        tail = new_Node;
    }
    void push_front(int value) {
        Node* new_Node = new Node;
        new_Node->data = value;
        new_Node->prev = nullptr;
        new_Node->next = head;
        if (head == nullptr) {
            head = new_Node;
            tail = new_Node;
            return;
        }
        head->prev = new_Node;
        head = new_Node;
    }

    void pop_front() {
        if (head == nullptr) {
            return;
        }
        Node* old_head = head;
        head = head->next;
        if (head == nullptr) {
            tail = nullptr;
        } else {
            head->prev = nullptr;
        }
        delete old_head;
    }
    void pop_back() {
        if (tail == nullptr) {
            return;
        }
        Node* old_tail = tail;
        tail = tail->prev;
        if (tail == nullptr) {
            head = nullptr;
        } else {
            tail->next = nullptr;
        }
        delete old_tail;
    }
    bool contains(int value) {
        Node* current = head;
        while (current != nullptr) {
            if (current->data == value) {
                return true;
            }
            current = current->next;
        }
        return false;
    }
    void print() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
    void print_reverse() {
        Node* current = tail;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->prev;
        }
        cout << endl;
    }
    bool empty() {
        return head == nullptr;
    }
    int size() {
        int count = 0;
        Node* current = head;
        while (current != nullptr) {
            count++;
            current = current->next;
        }
        return count;
    }
    ~List() {
        while (head != nullptr) {
            pop_front();
        }
    }
};
