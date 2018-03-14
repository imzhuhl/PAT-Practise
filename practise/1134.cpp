#include <iostream>

using namespace std;

int edge[10001][2];
int visit[10001];

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        edge[i][0] = a;
        edge[i][1] = b;
    }

    int k;
    scanf("%d", &k);
    for (int v = 0; v < k; v++) {
        fill(visit, visit + 10001, 0);
        int nv;
        scanf("%d", &nv);
        for (int i = 0; i < nv; i++) {
            int x;
            scanf("%d", &x);
            visit[x] = 1;
        }

        bool mark = true;
        for (int i = 0; i < m; i++) {
            int a = edge[i][0];
            int b = edge[i][1];
            if (visit[a] != 1 && visit[b] != 1) {
                mark = false;
                break;
            }
        }
        if (mark) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }

    return 0;
}