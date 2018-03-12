#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n, m;
    int coin[10001];
    int dp[10001][101] = {0};
    int check[10001][101] = {0};
    scanf("%d%d", &n, &m);

    for (int i = 1; i <= n; i++) {
        scanf("%d", &coin[i]);
    }
    sort(coin + 1, coin + n + 1, greater<int>());
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (j < coin[i]) {
                dp[i][j] = dp[i-1][j];
            }
            else if (dp[i - 1][j] <= dp[i - 1][j - coin[i]] + coin[i]) {
                dp[i][j] = dp[i - 1][j - coin[i]] + coin[i];
                check[i][j] = coin[i];
            } else {
                dp[i][j] = dp[i - 1][j];
                check[i][j] = check[i - 1][j];
            }
        }
        
    }

    if (dp[n][m] == m) {
        int sum = 0;
        int p = m;
        int r = n;
        while (sum < m) {
            int x = check[r][p];
            printf("%d", x);
            p = p - x;
            sum += x;
            r--;
            if (sum < m) printf(" ");
        }
        printf("\n");
    } else {
        printf("No Solution\n");
    }

    return 0;
}