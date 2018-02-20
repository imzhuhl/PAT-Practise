#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

int rst[10005];
int len;

bool back(int coins[], int begin, int size, int total, int idx) {
    if (total < 0) {
        return false;
    }
    if (total == 0) {
        len = idx;
        return true;
    }
    for (int i = begin; i < size; i++) {
        rst[idx] = coins[i];
        total -= coins[i];
        bool flag = back(coins, i + 1, size, total, idx + 1);
        if (flag) {
            return true;
        }
        total += coins[i];
    }
    return false;
    
}

int main() {
    int N, M;
    int coins[10005];

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        cin >> coins[i];
    }
    sort(coins, coins + N);
    
    bool flag = back(coins, 0, N, M, 0);
    if (flag) {
        for (int i = 0; i < len; i++) {
            if (i) printf(" ");
            printf("%d", rst[i]);
        }
        printf("\n");
    } else {
        printf("No Solution\n");
    }

    return 0;
}