#include <iostream>
#include <algorithm>
using namespace std;

const int inf = 99999999;
int N, M, c1, c2;
int cost[505];
int carnum[505];
int carmax[505] = {0};
int road[505][505];
int cnt[505] = {0};

void dijkstra() {
    bool mark[505];
    for (int i = 0; i < N; i++) {
        mark[i] = false;
        cost[i] = inf;
    }
    cost[c1] = 0;
    carmax[c1] = carnum[c1];
    cnt[c1] = 1;

    for (int j = 0; j < N; j++) {
        int mincost = inf;
        int id = -1;
        for (int i = 0; i < N; i++) {
            if (!mark[i] && mincost > cost[i]) {
                mincost = cost[i];
                id = i;
            }
        }
        if (id == -1) break;
        mark[id] = true;
        for (int i = 0; i < N; i++) {
            if (!mark[i]) {
                if (road[id][i] + cost[id] < cost[i]) {
                    cost[i] = road[id][i] + cost[id];
                    cnt[i] = cnt[id];
                    carmax[i] = carnum[i] + carmax[id];
                } else if (road[id][i] + cost[id] == cost[i]) {
                    cnt[i] += cnt[id];
                    if (carmax[id] + carnum[i] > carmax[i]) {
                        carmax[i] = carnum[i] + carmax[id];
                    }
                }
            }
        }
    }

}

int main() {
    scanf("%d%d%d%d", &N, &M, &c1, &c2);
    for (int i = 0; i < N; i++) {
        scanf("%d", &carnum[i]);
    }
    fill(road[0], road[0] + 505 * 505, inf);
    for (int i = 0; i < M; i++) {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        road[x][y] = road[y][x] = min(road[x][y], z);
    }

    dijkstra();

    printf("%d %d\n", cnt[c2], carmax[c2]);

    return 0;
}