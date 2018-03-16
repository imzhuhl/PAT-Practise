#include <iostream>
#include <queue>
using namespace std;

int n;
int all[22][2];
int pre[22];

int main() {
    scanf("%d", &n);
    for (int i = 0; i < 22; i++) {
        pre[i] = i;
    }
    for (int i = 0; i < n; i++) {
        char a[5], b[5];
        int x;
        scanf("%s %s", a, b);
        if (a[0] == '-') {
            all[i][0] = -1;
        } else {
            x = atoi(a);
            pre[x] = i;
            all[i][0] = x;
        }
        if (b[0] == '-') {
            all[i][1] = -1;
        } else {
            x = atoi(b);
            pre[x] = i;
            all[i][1] = x;
        }
    }

    int root;
    for (int i = 0; i < n; i++) {
        if (pre[i] == i) {
            root = i;
            break;
        }
    }

    bool flag = true;
    int last = 0;
    queue<int> qu;
    qu.push(root);
    while (!qu.empty()) {
        int x = qu.front();
        last = x;
        if (flag == false && (all[x][0] != -1 || all[x][1] != -1)) {
            break;
        }
        if (all[x][0] != -1) {
            qu.push(all[x][0]);
        } else {
            flag = false;
        }

        if (flag == false && all[x][1] != -1) {
            break;
        }
        if (all[x][1] != -1) {
            qu.push(all[x][1]);
        } else {
            flag = false;
        }
        qu.pop();
    }

    if (qu.empty()) {
        printf("YES %d\n", last);
    } else {
        printf("NO %d\n", root);
    }

    return 0;
}