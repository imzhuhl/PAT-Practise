#include <iostream>
#include <map>
#include <string>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

int n, k;
pair<string, string> all[1005];
int weight[1005];
int mark[1005];
map<string, int> gang;
queue<string> que;

int sum = 0;
map<string, int> rst;

int main() {
    scanf("%d%d", &n, &k);
    getchar();
    for (int i = 0; i < n; i++) {
        char a[5], b[5];
        scanf("%s %s", a, b);
        all[i].first = a;
        all[i].second = b;
        scanf("%d", &weight[i]);
    }

    for (int i = 0; i < n; i++) {
        if (mark[i] == 1) continue;
        int now = i;
        que.push(all[now].first);
        sum = 0;
        while (!que.empty()) {
            string name = que.front();
            que.pop();
            for (int j = 0; j < n; j++) {
                if (mark[j] != 1 && (all[j].first == name || all[j].second == name)) {
                    mark[j] = 1;
                    string name2;
                    if (all[j].first == name) {
                        name2 = all[j].second;
                    } else {
                        name2 = all[j].first;
                    }
                    que.push(name2);
                    if (gang.find(name) != gang.end()) {
                        gang[name] += weight[j];
                    } else {
                        gang[name] = weight[j];
                    }
                    if (gang.find(name2) != gang.end()) {
                        gang[name2] += weight[j];
                    } else {
                        gang[name2] = weight[j];
                    }
                    sum += weight[j];
                }
            }
        }
        if (sum > k && gang.size() > 2) {
            map<string, int>::iterator p, it = gang.begin();
            int num = it->second;
            p = it;
            it++;
            for (; it != gang.end(); it++) {
                if (it->second > num) {
                    p = it;
                    num = it->second;
                }
            }
            rst[p->first] = gang.size();
        }
        gang.clear();
    }

    printf("%lu\n", rst.size());
    map<string, int>::iterator it = rst.begin();
    for (; it != rst.end(); it++) {
        printf("%s %d\n", it->first.c_str(), it->second);
    }

    return 0;
}