#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int n;
int all[101][2];
int val[101];
int top = 0;

int node[101];

void inorder(int root) {
    if (root == -1) {
        return;
    }
    inorder(all[root][0]);
    node[root] = val[top++];
    inorder(all[root][1]);
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &all[i][0], &all[i][1]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &val[i]);
    }
    sort(val, val + n);
    inorder(0);

    queue<int> qu;
    qu.push(0);
    while (!qu.empty()) {
        int id = qu.front();
        qu.pop();
        if (id != 0) printf(" ");
        printf("%d", node[id]);
        if (all[id][0] != -1) qu.push(all[id][0]);
        if (all[id][1] != -1) qu.push(all[id][1]);
    }
    printf("\n");


    return 0;
}