#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, S;
int val[105];
vector<int> info[105];
int sq[105];
int top = 0;
vector<vector<int> > rst;

void dfs(int id, int sum, int top) {
    sum += val[id];
    sq[top++] = val[id];
    if (sum == S && info[id].size() == 0) {
        vector<int> vt(sq, sq + top);
        rst.push_back(vt);
    } else {
        for (int i = 0; i < info[id].size(); i++) {
            dfs(info[id][i], sum, top);
        }
    }
}

int main() {
    cin >> N >> M >> S;
    for (int i = 0; i < N; i++) {
        cin >> val[i];
    }
    for (int i = 0; i < M; i++) {
        int id, num;
        cin >> id >> num;
        for (int j = 0; j < num; j++) {
            int x;
            cin >> x;
            info[id].push_back(x);
        }
    }

    // printf("fdsfs\n");
    int sum = 0;
    dfs(0, sum, top);

    sort(rst.begin(), rst.end());
    for (int i = rst.size() - 1; i >= 0; i--) {
        for (int j = 0; j < rst[i].size(); j++) {
            if (j) printf(" ");
            printf("%d", rst[i][j]);
        }
        printf("\n");
    }

    return 0;
}