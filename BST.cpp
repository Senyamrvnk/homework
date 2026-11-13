#include <bits/stdc++.h>
using namespace std;

class BST {
private:
    struct Node {
        int value;
        int count;
        Node* left;
        Node* right;

        Node(int v) {
            value = v;
            count = 1;
            left = nullptr;
            right = nullptr;
        }
    };

    Node* root = nullptr;
    int sz = 0;
    int unique_sz = 0;

    void destroy(Node* node) {
        if (node == nullptr) return;

        destroy(node->left);
        destroy(node->right);
        delete node;
    }

    Node* insert(Node* node, int value) {
        if (node == nullptr) {
            sz++;
            unique_sz++;
            return new Node(value);
        }

        if (value < node->value) {
            node->left = insert(node->left, value);
        }
        else if (value > node->value) {
            node->right = insert(node->right, value);
        }
        else {
            node->count++;
            sz++;
        }

        return node;
    }

    bool contains(Node* node, int value) {
        if (node == nullptr) return false;

        if (value == node->value) return true;

        if (value < node->value)
            return contains(node->left, value);

        return contains(node->right, value);
    }

    Node* find_min(Node* node) {
        while (node->left != nullptr)
            node = node->left;

        return node;
    }

    Node* extract_min(Node* node) {
        if (node->left == nullptr) {
            Node* right = node->right;
            node->right = nullptr;
            delete node;
            return right;
        }

        node->left = extract_min(node->left);
        return node;
    }

    Node* erase_node(Node* node, int value) {
        if (node == nullptr) return nullptr;

        if (value < node->value) {
            node->left = erase_node(node->left, value);
        }
        else if (value > node->value) {
            node->right = erase_node(node->right, value);
        }
        else {
            if (node->left == nullptr) {
                Node* right = node->right;
                node->right = nullptr;
                delete node;
                return right;
            }

            if (node->right == nullptr) {
                Node* left = node->left;
                node->left = nullptr;
                delete node;
                return left;
            }

            Node* successor = find_min(node->right);

            node->value = successor->value;
            node->count = successor->count;

            node->right = extract_min(node->right);
        }

        return node;
    }

    void print(Node* node) {
        if (node == nullptr) return;

        print(node->left);

        for (int i = 0; i < node->count; i++)
            cout << node->value << " ";

        print(node->right);
    }

public:
    ~BST() {
        destroy(root);
    }

    void insert(int value) {
        root = insert(root, value);
    }

    bool contains(int value) {
        return contains(root, value);
    }

    void erase(int value) {
        if (!contains(value)) return;

        Node* node = root;

        while (node->value != value) {
            if (value < node->value)
                node = node->left;
            else
                node = node->right;
        }

        sz--;

        if (node->count > 1) {
            node->count--;
        }
        else {
            unique_sz--;
            root = erase_node(root, value);
        }
    }

    int size() {
        return sz;
    }

    int unique_size() {
        return unique_sz;
    }

    void print() {
        print(root);
        cout << endl;
    }
};
