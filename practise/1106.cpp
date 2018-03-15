#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<int> all[100000];

int n;
double p, r;
int mindeep = 99999999;
int cnt = 0;

void dfs(int v, int deep) {
    if (all[v].empty()) {
        if (mindeep > deep) {
            mindeep = deep;
            cnt = 1;
        } else if (mindeep == deep) {
            cnt++;
        }
    }
    for (int i = 0; i < all[v].size(); i++) {
        dfs(all[v][i], deep + 1);
    }
}

int main() {
    scanf("%d%lf%lf", &n, &p, &r);
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        for (int j = 0; j < x; j++) {
            int tmp;
            scanf("%d", &tmp);
            all[i].push_back(tmp);
        }
    }

    dfs(0, 0);
    double rst = p * pow((1 + r / 100), mindeep);
    printf("%.4lf %d\n", rst, cnt);

    return 0;
}