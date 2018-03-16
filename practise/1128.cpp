#include <iostream>
#include <vector>
using namespace std;

int main() {
    int k, n;
    // bool matrix[1001][1001];
    scanf("%d", &k);
    for (int v = 0; v < k; v++) {
        // fill(matrix[0], matrix[0] + 1001 * 1001, false);
        scanf("%d", &n);
        vector<int> vt;
        vt.resize(n + 1);
        bool mark = true;
        for (int i = 1; i <= n; i++) {
            scanf("%d", &vt[i]);
            for (int j = 1; j < i; j++) {
                int y = vt[j];
                if (vt[i] == y || vt[i] - i == y - j || vt[i] + i == y + j) {
                    mark = false;
                }

            }
        }
        if (mark) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
    return 0;
}