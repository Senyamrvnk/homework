#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int l;
    int r;
    int value;
    int index;
    Node* left;
    Node* right;
    Node(int left_border, int right_border) {
        l = left_border;
        r = right_border;
        value = 0;
        index = -1;
        left = nullptr;
        right = nullptr;
    }
};
class SegmentTree {
    Node* root;
    pair<int, int> combine(pair<int, int> a, pair<int, int> b) {
        if (a.first >= b.first) {
            return a;
        }
        return b;
    }
    Node* build(vector<int>& a, int l, int r) {
        Node* node = new Node(l, r);
        if (l == r) {
            node->value = a[l];
            node->index = l;
            return node;
        }
        int mid = (l + r) / 2;
        node->left = build(a, l, mid);
        node->right = build(a, mid + 1, r);
        pair<int, int> result = combine(
            {node->left->value, node->left->index},
            {node->right->value, node->right->index}
        );
        node->value = result.first;
        node->index = result.second;
        return node;
    }
    pair<int, int> query(Node* node, int l, int r) {
        if (l <= node->l && node->r <= r) {
            return {node->value, node->index};
        }
        int mid = (node->l + node->r) / 2;
        if (r <= mid) {
            return query(node->left, l, r);
        }
        if (l > mid) {
            return query(node->right, l, r);
        }
        pair<int, int> a = query(node->left, l, r);
        pair<int, int> b = query(node->right, l, r);
        return combine(a, b);
    }
    void update(Node* node, int pos, int val) {
        if (node->l == node->r) {
            node->value = val;
            node->index = pos;
            return;
        }
        int mid = (node->l + node->r) / 2;
        if (pos <= mid) {
            update(node->left, pos, val);
        } else {
            update(node->right, pos, val);
        }
        pair<int, int> result = combine(
            {node->left->value, node->left->index},
            {node->right->value, node->right->index}
        );
        node->value = result.first;
        node->index = result.second;
    }
public:
    SegmentTree(vector<int>& a, int n) {
        root = build(a, 1, n);
    }
    pair<int, int> query(int l, int r) {
        return query(root, l, r);
    }
    void update(int pos, int val) {
        update(root, pos, val);
    }
};