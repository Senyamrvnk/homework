#include <bits/stdc++.h>
using namespace std;

class Trie {
private:
    struct Node {
        Node* children[26];
        bool is_end;
        Node() {
            is_end = false;
            for (int i = 0; i < 26; i++) {
                children[i] = nullptr;
            }
        }
    };
    Node* root;

public:
    Trie() {
        root = new Node();
    }
    void insert(const string& word) {
        Node* v = root;
        for (char c : word) {
            int x = c - 'a';
            if (v->children[x] == nullptr) {
                v->children[x] = new Node();
            }
            v = v->children[x];
        }
        v->is_end = true;
    }
    bool search(const string& word) const {
        Node* v = root;
        for (char c : word) {
            int x = c - 'a';
            if (v->children[x] == nullptr) {
                return false;
            }
            v = v->children[x];
        }
        return v->is_end;
    }
    bool startsWith(const string& prefix) const {
        Node* v = root;
        for (char c : prefix) {
            int x = c - 'a';
            if (v->children[x] == nullptr) {
                return false;
            }
            v = v->children[x];
        }
        return true;
    }
};
