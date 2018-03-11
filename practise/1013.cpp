#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int N, M, K;
vector<int> road[1000];

int main() {
    scanf("%d%d%d", &N, &M, &K);
    for (int i = 0; i < M; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        road[x].push_back(y);
        road[y].push_back(x);
    }
    for (int i = 0; i < K; i++) {
        int lost;
        scanf("%d", &lost);
        int mark[1000] = {0};
        int cnt = 0;
        for (int i = 1; i <= N; i++) {
            if (mark[i] == 1 || i == lost) continue;
            stack<int> st;
            mark[i] = 1;
            for (int j = 0; j < road[i].size(); j++) {
                if (road[i][j] == lost) continue;
                st.push(road[i][j]);
                mark[road[i][j]] = 1;
            }
            while (!st.empty()) {
                int city = st.top();
                st.pop();
                for (int j = 0; j < road[city].size(); j++) {
                    if (road[city][j] == lost || mark[road[city][j]] == 1) continue;
                    st.push(road[city][j]);
                    mark[road[city][j]] = 1;
                }
            }
            cnt++;
        }
        printf("%d\n", cnt - 1);
    }

    return 0;
}