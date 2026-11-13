
#include <bits/stdc++.h>
using namespace std;

class Heap {
public:
    vector<pair<int, int>> arr;
    vector<int>& pos;

    Heap(vector<int>& p) : pos(p) {}

    void sift_up(int i) {
        while (i > 0) {
            int parent = (i - 1) / 2;
            if (arr[i].first <= arr[parent].first) {
                return;
            }
            swap(arr[i], arr[parent]);
            pos[arr[i].second] = i;
            pos[arr[parent].second] = parent;
            i = parent;
        }
    }
    void sift_down(int i) {
        while (true) {
            int max_index = i;
            int left = 2 * i + 1;
            int right = 2 * i + 2;
            if (left < arr.size() &&
                arr[left].first > arr[max_index].first) {
                max_index = left;
                }
            if (right < arr.size() &&
                arr[right].first > arr[max_index].first) {
                max_index = right;
                }
            if (max_index == i) {
                return;
            }
            swap(arr[i], arr[max_index]);
            pos[arr[i].second] = i;
            pos[arr[max_index].second] = max_index;
            i = max_index;
        }
    }
    void push(int next, int car) {
        arr.push_back({next, car});
        pos[car] = arr.size() - 1;
        sift_up(arr.size() - 1);
    }
    void update(int car, int next) {
        int i = pos[car];
        arr[i].first = next;
        sift_up(i);
    }
    int top() {
        return arr[0].second;
    }
    void pop() {
        int car = arr[0].second;
        swap(arr[0], arr[arr.size() - 1]);
        pos[arr[0].second] = 0;
        pos[arr[arr.size() - 1].second] = arr.size() - 1;
        arr.pop_back();
        pos[car] = -1;
        if (!arr.empty()) {
            sift_down(0);
        }
    }
    int size() {
        return arr.size();
    }
};