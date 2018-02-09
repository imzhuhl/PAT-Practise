#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
using namespace std;

const int inf = 1000000000;
const int N = 502;
int n;
bool mark[N];
int a[N][N];
int b[N];
int cost[N];
vector<int> pre[N];
vector<int> answer;
int bestin, bestout, m;

void dijkstra() {
    for (int i = 0; i < n; i++) {
        cost[i] = inf;
        mark[i] = false;
    }
    cost[0] = 0;
    for (int j = 0; j < n; j++) {
        int k = -1;
        for (int i = 0; i < n; i++) {
            if (!mark[i] && (k < 0 || cost[i] < cost[k])) {
                k = i;
            }
        }
        mark[k] = true;
        for (int i = 0; i < n; i++) {
            if (!mark[i] && a[k][i] < inf) {
                int temp = cost[k] + a[k][i];
                if (temp < cost[i]) {
                    cost[i] = temp;
                    pre[i].resize(1);
                    pre[i][0] = k;
                } else if (temp == cost[i]) {
                    pre[i].push_back(k);
                }
            }
        }
    }
}

void dfs(int now, int mayin, int mayout, vector<int> &path) {
    path.push_back(now);
    if (now == 0) {
        if ((mayin < bestin) || ((mayin == bestin) && (mayout < bestout))) {
            bestin = mayin;
            bestout = mayout;
            answer = path;
        }
        path.pop_back();
        return;
    }
    if (b[now] >= m) {
        mayin -= b[now] - m;
        if (mayin < 0) {
            mayout -= mayin;
            mayin = 0;
        }
        // mayout += b[now] - m;
    } else {
        mayin += m - b[now];
    }
    for (int i = 0; i < pre[now].size(); i++) {
        dfs(pre[now][i], mayin, mayout, path);
    }
    path.pop_back();
}

int main() {
    int p, to;
    scanf("%d%d%d%d", &m, &n, &to, &p);
    for (int i = 1; i <= n; i++) {
        scanf("%d", b + i);
    }
    n++;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            a[i][j] = inf;
        }
    }
    for (; p != 0; p--) {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        a[x][y] = a[y][x] = min(a[x][y], z);
    }

    m >>= 1;
    dijkstra();
    bestin = bestout = inf;
    vector<int> path;
    dfs(to, 0, 0, path);
    reverse(answer.begin(), answer.end());
    printf("%d ", bestin);
    for (int i = 0; i < answer.size(); i++) {
        if (i) {
            printf("->");
        }
        printf("%d", answer[i]);
    }
    printf(" %d\n", bestout);
    return 0;
}
