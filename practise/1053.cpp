#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, S;
int weig[101];
vector<int> all[101];
int leaf[101] = {0};
int road[101];
vector<int> rst[101];
int cnt = 0;;

void dfs(int root, int top, int sum) {
    int weight = weig[root];
    road[top] = weight;
    sum += weight;
    if (sum == S && leaf[root] == 0) {
        rst[cnt++] = vector<int>(road, road + top + 1);
        return;
    } else {
        if (sum > S) return;
        for (int i = 0; i < all[root].size(); i++) {
            dfs(all[root][i], top + 1, sum);
        }
    }

}

int main() {
    scanf("%d%d%d", &N, &M, &S);
    for (int i = 0; i < N; i++) {
        scanf("%d", &weig[i]);
    }
    for (int i = 0; i < M; i++) {
        int faid, chinum;
        scanf("%d%d", &faid, &chinum);
        leaf[faid] = 1;
        for (int j = 0; j < chinum; j++) {
            int chid;
            scanf("%d", &chid);
            all[faid].push_back(chid);
        }
    }

    int top = 0;
    int sum = 0;
    dfs(0, top, sum);

    sort(rst, rst + cnt);
    for (int i = cnt - 1; i >= 0; i--) {
        for (int j = 0; j < rst[i].size(); j++) {
            if (j) printf(" ");
            printf("%d", rst[i][j]);
        }
        printf("\n");
    }

    return 0;
}