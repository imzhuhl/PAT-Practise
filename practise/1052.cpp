#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, head;

struct Node {
    int addr;
    int val;
    int next;
    int flag;
}node[100000];

const int inf = 99999999;
bool cmp(Node &a, Node &b) {
    if (a.flag == 1 && b.flag == 1) {
        return a.val < b.val;
    } else {
        return a.flag > b.flag;
    }
}

int main() {

    scanf("%d%d", &n, &head);
    for (int i = 0; i < n; i++) {
        int addr, val, nadd;
        scanf("%d%d%d", &addr, &val, &nadd);
        node[addr].addr = addr;
        node[addr].val = val;
        node[addr].next = nadd;
    }

    int p = head;
    int len = 0;
    while (p != -1) {
        node[p].flag = 1;
        len++;
        p = node[p].next;
    }

    sort(node, node + 100000, cmp);

    if (len == 0) {
        printf("%d -1\n", len);
        return 0;
    }
    printf("%d %05d\n", len, node[0].addr);
    for (int i = 0; i < len; i++) {
        printf("%05d %d ", node[i].addr, node[i].val);
        if (i == len - 1) printf("-1\n");
        else printf("%05d\n", node[i + 1].addr);
    }

    
    return 0;
}