#include <iostream>
#include <map>
#include <vector>
#include <set>
using namespace std;

vector<int> node[10000];
vector<int> belong[10000];
vector<int> path, tmp;
int visit[10000];
int maxdeep, maxmul;

void findway(int curr, int dest, int deep, int mul) {
    path.push_back(curr);
    visit[curr] = 1;
    if (belong[curr].size() > 1) {
        mul++;
    }
    if (curr == dest) {
        if (deep < maxdeep) {
            maxdeep = deep;
            maxmul = mul;
            tmp = path;
        } else if (deep == maxdeep && mul < maxmul) {
            maxmul = mul;
            tmp = path;
        }
        visit[path[path.size() - 1]] = 0;
        path.pop_back();
        return;
    }

    for (int i = 0; i < node[curr].size(); i++) {
        if (visit[node[curr][i]] != 1)
            findway(node[curr][i], dest, deep + 1, mul);
    }
    visit[path[path.size() - 1]] = 0;
    path.pop_back();
}

int main() {
    int n;
    scanf("%d", &n);
    for (int v = 1; v <= n; v++) {
        int m;
        scanf("%d", &m);
        vector<int> vt;
        vt.resize(m);
        for (int i = 0; i < m; i++) {
            scanf("%d", &vt[i]);
            belong[vt[i]].push_back(v);
            if (i > 0)
                node[vt[i]].push_back(vt[i - 1]);
        }
        for (int i = 0; i < m - 1; i++) {
            node[vt[i]].push_back(vt[i + 1]);
        }

    }
    int k;
    scanf("%d", &k);
    for (int v = 0; v < k; v++) {
        int src, dest;
        scanf("%d%d", &src, &dest);
        maxdeep = 99999999;
        maxmul = 99999999;
        path.clear();
        tmp.clear();
        fill(visit, visit + 10000, 0);
        findway(src, dest, 0, 0);
        
        printf("%lu\n", tmp.size() - 1);
        int first = tmp[0];
        int currline = -1;
        for (int i = 0; i < tmp.size() - 1; i++) {
            if (belong[tmp[i]].size() != 1) {
                if (currline == -1) {
                    for (int j = 0; j < belong[tmp[i]].size(); j++) {
                        int line = belong[tmp[i]][j];
                        for (int l = 0; l < belong[tmp[i + 1]].size(); l++) {
                            if (line == belong[tmp[i + 1]][l]) {
                                currline = line;
                                break;
                            }
                        }
                    }
                    continue;
                }
                int oneline = 0;
                for (int j = 0; j < belong[tmp[i + 1]].size(); j++) {
                    if (belong[tmp[i + 1]][j] == currline) {
                        oneline = 1;
                        break;
                    }
                }
                if (oneline == 0) {
                    printf("Take Line#%d from %04d to %04d.\n", currline, first, tmp[i]);
                    first = tmp[i];
                    for (int j = 0; j < belong[tmp[i]].size(); j++) {
                        int line = belong[tmp[i]][j];
                        for (int l = 0; l < belong[tmp[i + 1]].size(); l++) {
                            if (line == belong[tmp[i + 1]][l]) {
                                currline = line;
                                break;
                            }
                        }
                    }
                }
            } else {
                currline = belong[tmp[i]][0];
            }
        }
        printf("Take Line#%d from %04d to %04d.\n", currline, first, tmp[tmp.size() - 1]);

    }

    return 0;
}