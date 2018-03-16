#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int n, k;
pair<string, int> info[10001];
int order[10000];

bool cmp(pair<string, int> &a, pair<string, int> &b) {
    if (a.second == b.second) {
        return a.first < b.first;
    }
    return a.second > b.second;

}

int main() {
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++) {
        string name;
        int tall;
        cin >> name >> tall;
        info[i].first = name;
        info[i].second = tall;
    }

    sort(info + 1, info + n + 1, cmp);

    int col = n / k;
    int onecol = n % k + col;
    int p = onecol / 2 + 1;
    for (int i = 1; i <= onecol; i++) {
        int idx;
        if (i % 2 == 0) {
            idx = p - i / 2;
        } else {
            idx = p + i / 2;
        }
        order[idx] = i;
    }
    for (int i = 1; i <= onecol; i++) {
        if (i != 1) printf(" ");
        printf("%s", info[order[i]].first.c_str());
    }
    printf("\n");

    int start = onecol;
    p = col / 2 + 1;
    for (int j = 1; j < k; j++) {
        for (int i = 1; i <= col; i++) {
            int idx;
            if (i % 2 == 0) {
                idx = p - i / 2;
            } else {
                idx = p + i / 2;
            }
            order[idx] = i + start;
        }

        for (int i = 1; i <= col; i++) {
            if (i != 1) printf(" ");
            printf("%s", info[order[i]].first.c_str());
        }
        printf("\n");

        start += col;
    }

    return 0;
}