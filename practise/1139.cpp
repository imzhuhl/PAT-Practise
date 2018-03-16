#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

map<int, set<int> > all;

bool cmp(pair<int, int> &a, pair<int, int> &b) {
    if (a.first == b.first) 
        return a.second < b.second;
    return a.first < b.first;
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        all[a].insert(b);
        all[b].insert(a);
    }
    int k;
    scanf("%d", &k);
    for (int q = 0; q < k; q++) {
        int a, b;
        scanf("%d%d", &a, &b);
        // printf("%d %d\n", a, b);
        
        vector<pair<int, int> > rst;
        // multimap<int, int> rst;
        set<int> left = all[a], right = all[b];
        set<int>::iterator lit, rit;
        for (lit = left.begin(); lit != left.end(); lit++) {
            if ((a > 0 && *lit < 0) || (a < 0 && *lit > 0))
                continue;
            if (*lit == a || *lit == b)
                continue;
            for (rit = right.begin(); rit != right.end(); rit++) {
                if ((b > 0 && *rit < 0) || (b < 0 && *rit > 0))
                    continue;
                if (*rit == b || *rit == a || *rit == *lit)
                    continue;

                if (all[*lit].find(*rit) != all[*lit].end()) {
                    // printf("find: %d %d\n", *lit, *rit);
                    pair<int, int> x(abs(*lit), abs(*rit));
                    rst.push_back(x);
                    // rst.insert(pair<int, int>(abs(*lit),abs(*rit)));
                }
            }
        }
        int len = rst.size();
        printf("%d\n", len);
        sort(rst.begin(), rst.end(), cmp);
        for (int i = 0; i < len; i++) {
            printf("%04d %04d\n", rst[i].first, rst[i].second);
        }

    }

    return 0;
}