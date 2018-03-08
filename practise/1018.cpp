#include <iostream>
#include <stack>
#include <algorithm>
#include <cmath>
using namespace std;

const int inf = 99999999;
int cmax, N, sp, M;
int bike[501];
int road[501][501];
int cost[501];
int need[501];
int pre[501];

void dijkstra() {
    int mark[501] = {0};
    fill(cost, cost + 501, inf);
    cost[0] = 0;
    need[0] = 0;

    for (int j = 0; j <= N; j++) {
        int mincost = inf, idx = -1;
        for (int i = 0; i <= N; i++) {
            if (mark[i] == 0 && mincost > cost[i]) {
                mincost = cost[i];
                idx = i;
            }
        }
        if (idx == -1) break;
        mark[idx] = 1;
        for (int i = 0; i <= N; i++) {
            if (mark[i] == 0) {
                if (cost[i] > cost[idx] + road[idx][i]) {
                    cost[i] = cost[idx] + road[idx][i];
                    pre[i] = idx;
                    need[i] = need[idx] + (cmax / 2 - bike[i]);
                } else if (cost[i] == cost[idx] + road[idx][i]) {
                    int newneed = need[idx] + (cmax / 2 - bike[i]);
                    if (newneed < 0 && need[i] < 0) {
                        if (newneed > need[i]) {
                            pre[i] = idx;
                            need[i] = newneed;
                        }
                    } else {
                        if (newneed < need[i]) {
                            pre[i] = idx;
                            need[i] = newneed;
                        }
                    }
                }
            }
        }
    }

}

int main() {
    scanf("%d%d%d%d", &cmax, &N, &sp, &M);
    for (int i = 1; i <= N; i++) {
        scanf("%d", &bike[i]);
    }
    fill(road[0], road[0] + 501 * 501, inf);
    for (int i = 1; i <= M; i++) {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        road[x][y] = road[y][x] = min(road[x][y], z);
    }
    dijkstra();

    int in = 0, out = 0;
    if (need[sp] > 0) out = need[sp];
    else in = -need[sp];

    printf("%d ", out);
    stack<int> way;
    int x = sp;
    way.push(x);
    while (x != 0) {
        x = pre[x];
        way.push(x);
    }
    while (!way.empty()) {
        int x = way.top();
        if (x != 0) printf("->");
        printf("%d", x);
        way.pop();
    }
    printf(" %d\n", in);

    return 0;
}