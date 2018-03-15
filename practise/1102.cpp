#include <iostream>
#include <queue>
using namespace std;

int node[12][2];
int pre[12];
int root;
int cnt = 0;

void inorder(int v) {
    if (v == -1) 
        return;
    inorder(node[v][1]);
    if (cnt) printf(" ");
    printf("%d", v);
    cnt++;
    inorder(node[v][0]);
}

void levelorder(int root) {
    int top = 0;
    queue<int> qt;
    qt.push(root);
    while (qt.empty() == false) {
        int x = qt.front();
        if (top) printf(" ");
        printf("%d", x);
        top++;
        qt.pop();
        if (node[x][1] != -1)
            qt.push(node[x][1]);
        if (node[x][0] != -1)
            qt.push(node[x][0]);
    }
    printf("\n");
}


int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        pre[i] = i;
        node[i][0] = -1;
        node[i][1] = -1;
    }

    for (int i = 0; i < n; i++) {
        char a[4], b[4];
        scanf("%s %s", a, b);
        if (a[0] != '-') {
            int x = atoi(a);
            pre[x] = i;
            node[i][0] = x;
        }
        if (b[0] != '-') {
            int x = atoi(b);
            pre[x] = i;
            node[i][1] = x;
        }
    }

    for (int i = 0; i < n; i++) {
        if (pre[i] == i) {
            root = i;
            break;
        }
    }

    levelorder(root);

    inorder(root);
    printf("\n");


    return 0;
}