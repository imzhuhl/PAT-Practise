#include <iostream>
using namespace std;


int main() {
    int n, m, L;
    int faddr[201];
    int all[10001];
    int top = 0;
    int mark[201] = {0};
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        int x;
        scanf("%d", &x);
        faddr[x] = i;
        mark[x] = 1;

    }
    scanf("%d", &L);
    for (int i = 0; i < L; i++) {
        int x;
        scanf("%d", &x);
        if (mark[x] == 1) {
            all[top++] = x;
        }
    }

    int dp[10001] = {0};
    for (int i = 0; i < top; i++) {
        int color = all[i];
        int maxlen = 0;
        for (int j = 0; j < i; j++) {
            int len;
            if (faddr[all[j]] <= faddr[color]) {
                 len = dp[j];
                 if (maxlen < len)
                    maxlen = len;
            }
        }
        dp[i] = maxlen + 1;
    }

    printf("%d\n", dp[top - 1]);



    return 0;
}