#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int addr, val, next;
}node[100000];
vector<int> rst;
int head, n, k;

int main() {
    scanf("%d%d%d", &head, &n, &k);
    for (int i = 0; i < n; i++) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        node[a].addr = a;
        node[a].val = b;
        node[a].next = c;
    }
    int p = head;
    while (p != -1) {
        rst.push_back(p);
        p = node[p].next;
    }
    int len = rst.size();
    int circle = len / k;
    for (int i = 0; i < circle; i++) {
        int start = i * k, end = (i + 1) * k;
        for (int j = end - 1; j >= start; j--) {
            if (j != k - 1) printf("%05d\n", rst[j]);
            printf("%05d %d ", rst[j], node[rst[j]].val);
        }
    }
    int rest = len % k;
    for (int i = circle * k; i < circle * k + rest; i++) {
        printf("%05d\n", rst[i]);
        printf("%05d %d ", rst[i], node[rst[i]].val);
    }
    printf("-1\n");
    return 0;
}