#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;
    int cost[100005];
    int sum = 0;
    for (int i = 1; i <= N; i++) {
        cin >> cost[i];
        sum += cost[i];
        cost[i] = sum;
    }

    int M;
    cin >> M;
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        if (a > b) {
            swap(a, b);
        }
        int len1 = cost[b - 1] - cost[a - 1];
        
        int len2 = sum - len1;
        if (len2 > len1) {
            printf("%d\n", len1);
        } else {
            printf("%d\n", len2);
        }

    }

    return 0;
}