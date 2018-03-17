#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> ori, curr;

bool compare(vector<int> &a) {
    bool mark = true;
    for (int i = 0; i < n; i++) {
        if (a[i] != curr[i]) {
            mark = false;
            break;
        }
    }
    return mark;
}

void print(vector<int> &a) {
    for (int i = 0; i < n; i++) {
        if (i) printf(" ");
        printf("%d", a[i]);
    }
    printf("\n");
}

void max_heapify(vector<int> &vt, int start, int end) {
    int dad = start;
    int son = dad * 2 + 1;
    while (son <= end) {
        if (son + 1 <= end && vt[son] < vt[son + 1]) {
            son++;
        }
        if (vt[dad] < vt[son]) {
            swap(vt[dad], vt[son]);
            dad = son;
            son = dad * 2 + 1;
        } else {
            return ;
        }
    }
}

int main() {
    scanf("%d", &n);
    ori.resize(n);
    curr.resize(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &ori[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &curr[i]);
    }

    vector<int> ins = ori;
    bool mark = false;
    for (int i = 0; i < n; i++) {
        int tmp = ins[i];
        for (int j = i - 1; j >= 0; j--) {
            if (tmp < ins[j]) {
                ins[j + 1] = ins[j];
                ins[j] = tmp;
            } else {
                break;
            }
        }
        if (mark) break;
        if (compare(ins)) mark = true;
    }

    if (mark) {
        // insertion
        printf("Insertion Sort\n");
        print(ins);
    } else {
        // heap
        vector<int> hep = curr;
        int len = curr.size();
        bool mark = false;
        int idx;
        sort(ori.begin(), ori.end());
        for (int i = len - 1; i >= 0; i--) {
            if (curr[i] != ori[i]) {
                idx = i;
                break;
            }
        }

        swap(hep[0], hep[idx]);
        max_heapify(hep, 0, idx - 1);
    
        printf("Heap Sort\n");
        print(hep);
    }

    return 0;
}