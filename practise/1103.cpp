#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int n, k, p;
vector<int> tmp, rst;
int maxvalue = 0;

void dfs(int v, int sum) {
    // printf("%d\n", v);
    tmp.push_back(v);
    if (tmp.size() > k) {
        tmp.pop_back();
        return;
    }
    int val = pow(v, p);
    sum += val;
    if (sum == n && tmp.size() == k) {
        int tmsum = 0;
        for (int i = 0; i < k; i++) {
            tmsum += tmp[i];
        }
        if (tmsum > maxvalue) {
            maxvalue = tmsum;
            rst = tmp;
        } else if (tmsum == maxvalue) {
            int idx;
            for (int i = 0; i < k; i++) {
                if (tmp[i] != rst[i]) {
                    idx = i;
                    break;
                }
            }
            if (tmp[idx] > rst[idx]) {
                rst = tmp;
            }
        }
        tmp.pop_back();
        return;
    } 
    if (sum > n) {
        tmp.pop_back();
        return;
    }
    for (int i = v; i >= 1; i--) {
        dfs(i, sum);
    }
    tmp.pop_back();
}

int main() {
    scanf("%d%d%d", &n, &k, &p);
    int start = 0;
    for (int i = 1; i <= n; i++) {
        if (pow(i, p) >= n) {
            start = i;
            break;
        }
    }
    // printf("%d\n", start);
    for (int i = start; i > 0; i--) {
        dfs(i, 0);
    }

    if (rst.empty()) {
        printf("Impossible\n");
        return 0;
    }
    printf("%d = ", n);
    for (int i = 0; i < rst.size(); i++) {
        if (i) printf(" + ");
        printf("%d^%d", rst[i], p);
    }
    printf("\n");

    return 0;
}