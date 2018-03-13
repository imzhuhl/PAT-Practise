#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

const int inf = 99999999;
int n, k;
int dest;
map<string, int> cityname;
map<int, string> cityid;
int happ[202] = {0};
int road[202][202];
vector<int> pre[202];
vector<int> vt;
vector<int> path;
int maxhappy = 0;
int pathcnt = 0;

void dfs(int dest) {
    path.push_back(dest);
    if (dest == 0) {
        int happy = 0;
        for (int i = 0; i < path.size(); i++) {
            happy += happ[path[i]];
        }
        if (happy > maxhappy) {
            maxhappy = happy;
            vt = path;
        } else if (happy == maxhappy) {
            if (vt.size() > path.size()) {
                vt = path;
            }
        }
        pathcnt++;
        path.pop_back();
        return;
    }
    for (int i = 0; i < pre[dest].size(); i++) {
        dfs(pre[dest][i]);
    }
    path.pop_back();
}

int main() {
    scanf("%d%d", &n, &k);
    string S;
    cin >> S;
    cityname[S] = 0;
    cityid[0] = S;
    for (int i = 1; i < n; i++) {
        cin >> S;
        cityname[S] = i;
        cityid[i] = S;
        if (S == "ROM") dest = i;
        scanf("%d", &happ[i]);
    }
    fill(road[0], road[0] + 202 * 202, inf);
    for (int i = 0; i < k; i++) {
        string a, b;
        int length;
        cin >> a >> b >> length;
        int c1 = cityname[a];
        int c2 = cityname[b];
        road[c1][c2] = road[c2][c1] = length;
    }

    int cost[202];
    int visit[202] = {0};
    fill(cost, cost + 202, inf);
    cost[0] = 0;
    for (int i = 0; i < n; i++) {
        int idx = -1, mincost = inf;
        for (int j = 0; j < n; j++) {
            if (mincost > cost[j] && visit[j] == 0) {
                mincost = cost[j];
                idx = j;
            }
        }
        if (idx == -1) break;
        visit[idx] = 1;
        for (int j = 0; j < n; j++) {
            if (visit[j] == 0 && road[idx][j] != inf) {
                if (cost[j] > road[idx][j] + cost[idx]) {
                    pre[j].clear();
                    pre[j].push_back(idx);
                    cost[j] = road[idx][j] + cost[idx];
                } else if (cost[j] == road[idx][j] + cost[idx]) {
                    pre[j].push_back(idx);
                }
            }
        }
    }

    dfs(dest);

    double avghappy = maxhappy / (vt.size() - 1);
    printf("%d %d %d %d\n", pathcnt, cost[dest], maxhappy, (int)avghappy);
    printf("%s", cityid[0].c_str());
    for (int i = vt.size() - 2; i >= 0; i--) {
        printf("->%s", cityid[vt[i]].c_str());
    }
    printf("\n");
    

    return 0;
}