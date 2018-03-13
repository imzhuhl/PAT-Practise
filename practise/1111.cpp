#include <iostream>
#include <vector>
using namespace std;

const int inf = 99999999;
int n, m;
int road[501][501] = {0};
int length[501][501], rtime[501][501];
int dest,src;
vector<int> lenpath, timepath;
vector<int> tmp;
vector<int> pre[501];
vector<int> tpre[501];

int len_mintime = inf;
int time_minlen = inf;

void lendfs(int v) {
    tmp.push_back(v);
    if (v == src) {
        int sumtime = 0;
        for (int i = 1; i < tmp.size(); i++) {
            sumtime += rtime[tmp[i]][tmp[i-1]];
        }
        if (sumtime < len_mintime) {
            len_mintime = sumtime;
            lenpath = tmp;
        }
        tmp.pop_back();
        return;
    }
    for (int i = 0; i < pre[v].size(); i++) {
        lendfs(pre[v][i]);
    }
    tmp.pop_back();
}

void timedfs(int v) {
    tmp.push_back(v);
    if (v == src) {
        if (time_minlen > tmp.size()) {
            time_minlen = tmp.size();
            timepath = tmp;
        }
        tmp.pop_back();
        return;
    }
    for (int i = 0; i < tpre[v].size(); i++) {
        timedfs(tpre[v][i]);
    }
    tmp.pop_back();
}

int main() {
    scanf("%d%d", &n, &m);
    fill(length[0], length[0] + 501 * 501, inf);
    fill(rtime[0], rtime[0] + 501 * 501, inf);
    for (int i = 0; i < m; i++) {
        int v1, v2, oneway, leng, ti;
        cin >> v1 >> v2 >> oneway >> leng >> ti;
        road[v1][v2] = 1;
        length[v1][v2] = leng;
        rtime[v1][v2] = ti;
        if (oneway == 0) {
            road[v2][v1] = 1;
            length[v2][v1] = leng;
            rtime[v2][v1] = ti;
        }
    }
    cin >> src >> dest;

    int lencost[501];
    int visit[501] = {0};
    fill(lencost, lencost + 501, inf);
    lencost[src] = 0;
    for (int j = 0; j < n; j++) {
        int idx = -1, minlencost = inf;
        for (int i = 0; i < n; i++) {
            if (minlencost > lencost[i] && visit[i] == 0) {
                minlencost = lencost[i];
                idx = i;
            }
        }
        if (idx == -1) break;
        visit[idx] = 1;

        for (int i = 0; i < n; i++) {
            if (visit[i] == 0 && length[idx][i] != inf) {
                if (lencost[i] > lencost[idx] + length[idx][i]) {
                    lencost[i] = lencost[idx] + length[idx][i];
                    pre[i].clear();
                    pre[i].push_back(idx);
                } else if (lencost[i] == lencost[idx] + length[idx][i]) {
                    pre[i].push_back(idx);
                }
            }
        }
    }
    lendfs(dest);

    int timecost[501];
    fill(visit, visit + 501, 0);
    fill(timecost, timecost + 501, inf);
    timecost[src] = 0;
    for (int j = 0; j < n; j++) {
        int idx = -1, mintimecost = inf;
        for (int i = 0; i < n; i++) {
            if (mintimecost > timecost[i] && visit[i] == 0) {
                mintimecost = timecost[i];
                idx = i;
            }
        }
        if (idx == -1) break;
        visit[idx] = 1;

        for (int i = 0; i < n; i++) {
            if (visit[i] == 0 && rtime[idx][i] != inf) {
                if (timecost[i] > timecost[idx] + rtime[idx][i]) {
                    timecost[i] = timecost[idx] + rtime[idx][i];
                    tpre[i].clear();
                    tpre[i].push_back(idx);
                } else if (timecost[i] == timecost[idx] + rtime[idx][i]) {
                    tpre[i].push_back(idx);
                }
            }
        }
    }
    tmp.clear();
    timedfs(dest);

    bool mark = true;
    if (lenpath.size() != timepath.size()) mark = false;
    else {
        for (int i = 0; i < lenpath.size(); i++) {
            if (lenpath[i] != timepath[i]) {
                mark = false;
            }
        }
    }

    if (mark) {
        printf("Distance = %d; Time = %d: %d", lencost[dest], timecost[dest], lenpath[lenpath.size() - 1]);
        for (int i = lenpath.size() - 2; i >= 0; i--) {
            printf(" -> %d", lenpath[i]);
        }
        printf("\n");
    } else {
        printf("Distance = %d: %d", lencost[dest], lenpath[lenpath.size() - 1]);
        for (int i = lenpath.size() - 2; i >= 0; i--) {
            printf(" -> %d", lenpath[i]);
        }
        printf("\n");
        printf("Time = %d: %d", timecost[dest], timepath[timepath.size() - 1]);
        for (int i = timepath.size() - 2; i >= 0; i--) {
            printf(" -> %d", timepath[i]);
        }
        printf("\n");
    }
    

    return 0;
}