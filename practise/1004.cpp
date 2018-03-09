#include <iostream>
#include <queue>
using namespace std;

struct Node {
    int childnum;
    bool mark;
    Node *pre;
    int childid[100];
}node[105];

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        int faid, num, leafid;
        scanf("%d%d", &faid, &num);
        Node *fa = &node[faid];
        if (fa->mark == false) {
            fa->pre = 0;
            fa->mark = true;
        }
        fa->childnum = num;
        for (int i = 0; i < num; i++) {
            scanf("%d", &leafid);
            Node *chi = &node[leafid];
            fa->childid[i] = leafid;
            if (chi->mark == false) {
                chi->childnum = 0;
                chi->mark = true;
            }
            chi->pre = fa;
        }
    }

    Node *root = 0;
    queue<int> que;
    int level[101] = {0};
    int book[101] = {0};
    int maxlevel = 0;
    que.push(1);
    level[1] = 1;
    while (!que.empty()) {
        int id = que.front();
        que.pop();
        root = &node[id];
        maxlevel = max(maxlevel , level[id]);
        for (int i = 0; i < root->childnum; i++) {
            int chid = root->childid[i];
            level[chid] = level[id] + 1;
            que.push(root->childid[i]);
        }
        if (root->childnum == 0) {
            book[level[id]]++;
        }
    }
    for (int i = 1; i <= maxlevel; i++) {
        if (i != 1) printf(" ");
        printf("%d", book[i]);
    }
    printf("\n");
    



    return 0;
}