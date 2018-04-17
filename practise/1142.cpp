#include <iostream>
#include <vector>
using namespace std;

int nv, ne;
int m;
int road[205][205] = {0};
int info[205];
int visit[205];

int main() {
    scanf("%d%d", &nv, &ne);
    int a, b;
    for (int i = 0; i < ne; i++) {
        scanf("%d%d", &a, &b);
        road[a][b] = road[b][a] = 1;
    }
    scanf("%d", &m);
    int k;
    for (int v = 0; v < m; v++) {
        scanf("%d", &k);
        fill(visit, visit + 205, 0);
        for (int i = 0; i < k; i++) {
            scanf("%d", &info[i]);
            visit[info[i]] = 1;
        }

        int mark = 1;
        for (int i = 0; i < k; i++) {
            for (int j = i + 1; j < k; j++) {
                if (road[info[i]][info[j]] == 0) {
                    mark = 0;
                    break;
                }
            }
            if (mark == 0) break;
        }
        if (mark == 0) {
            printf("Not a Clique\n");
            continue;
        }

        mark = 1;
        for (int i = 1; i <= nv; i++) {
            if (visit[i] == 1) continue;
            for (int j = 0; j < k; j++) {
                if (road[i][info[j]] == 0) break;
                if (j == k - 1) mark = 0;
            }
            if (mark == 0) {
                printf("Not Maximal\n");
                break;
            }
        }
        if (mark == 1)
            printf("Yes\n");
        
    }

    return 0;
}