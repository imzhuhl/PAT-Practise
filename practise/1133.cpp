#include <iostream>
#include <vector>
using namespace std;

int head, n, k;
int nxt[100001];
int val[100001];

vector<int> smaller, mid, larger;

int main() {
    scanf("%d%d%d", &head, &n, &k);
    for (int i = 0; i < n; i++) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        nxt[a] = c;
        val[a] = b;
    }

    int p = head;
    while (p != -1) {
        if (val[p] < 0) {
            smaller.push_back(p);
        } else if (val[p] > k) {
            larger.push_back(p);
        } else {
            mid.push_back(p);
        }
        p = nxt[p];
    }

    if (!smaller.empty()) {
        printf("%05d %d ", smaller[0], val[smaller[0]]);
        for (int i = 1; i < smaller.size(); i++) {
            printf("%05d\n", smaller[i]);
            printf("%05d %d ", smaller[i], val[smaller[i]]);
        }
    }
    if (!mid.empty()) {
        if (smaller.empty()) {
            printf("%05d %d ", mid[0], val[mid[0]]);
        } else {
            printf("%05d\n", mid[0]);
            printf("%05d %d ", mid[0], val[mid[0]]);
        }
        for (int i = 1; i < mid.size(); i++) {
            printf("%05d\n", mid[i]);
            printf("%05d %d ", mid[i], val[mid[i]]);
        }
    }
    if (!larger.empty()) {
        if (smaller.empty() && mid.empty()) {
            printf("%05d %d ", larger[0], val[larger[0]]);
        } else {
            printf("%05d\n", larger[0]);
            printf("%05d %d ", larger[0], val[larger[0]]);
        }
        for (int i = 1; i < larger.size(); i++) {
            printf("%05d\n", larger[i]);
            printf("%05d %d ", larger[i], val[larger[i]]);
        }
    }
    printf("-1\n");
    


    return 0;
}