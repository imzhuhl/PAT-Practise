#include <iostream>
#include <string>
#include <algorithm>
using namespace std;


int N, M, K, ds;
int road[10005][3];

int mark[1100];
int cost[1100];

void dijkstra(int id) {
    for (int i = 1; i <= N + M; i++) {
        mark[i] = 0;
        cost[i] = 0x7fffffff;
    }
    mark[id] = 1;
    cost[id] = 0;
    for (int i = 1; i <= N + M; i++) {

        for (int j = 0; j < K; j++) {
            if (road[j][0] == id || road[j][1] == id) {
                int x;
                if (road[j][0] == id) {
                    x = road[j][1];
                } else {
                    x = road[j][0];
                }
                if (mark[x] != 1 && cost[x] > road[j][2] + cost[id]) {
                    cost[x] = road[j][2] + cost[id];
                }
            }
        }

        int min = 0x7fffffff, minid = -1;
        for (int i = 1; i <= N + M; i++) {
            if (mark[i] != 1 && min > cost[i]) {
                min = cost[i];
                minid = i;
            }
        }

        if (minid == -1) {
            break;
        }
        id = minid;
        mark[id] = 1;
    }
}

int main() {
    cin >> N >> M >> K >> ds;

    for (int i = 0; i < K; i++) {
        string in[3];
        cin >> in[0] >> in[1] >> road[i][2];
        if (in[0][0] == 'G') {
            in[0][0] = '0';
            road[i][0] = atoi(in[0].c_str()) + N;
        } else {
            road[i][0] = atoi(in[0].c_str());
        }
        
        if (in[1][0] == 'G') {
            in[1][0] = '0';
            road[i][1] = atoi(in[1].c_str()) + N;
        } else {
            road[i][1] = atoi(in[1].c_str());
        }
    }

    int val = 0;
    int minsum = 0;
    int gasidx = -1;
    for (int i = N + 1; i <= N + M; i++) {
        dijkstra(i);
        int x = *min_element(cost + 1, cost + N + 1);
        int y = *max_element(cost + 1, cost + N + 1);
        if (y > ds) {
            continue;
        }
        if (val < x) {
            val = x;
            int sum = 0;
            for (int j = 1; j <= N; j++) {
                sum += cost[j];
            }
            minsum = sum;
            gasidx = i;
        } else if (val == x) {
            int sum = 0;
            for (int j = 1; j <= N; j++) {
                sum += cost[j];
            }
            if (minsum > sum) {
                minsum = sum;
                gasidx = i;
            }
        }
    }
    if (gasidx == -1) {
        printf("No Solution\n");
        return 0;
    }
    printf("G%d\n", gasidx - N);
    printf("%d.0 %.1lf\n", val, minsum * 1.0 / N);

    return 0;
}