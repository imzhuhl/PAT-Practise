#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

set<int> visit;
int m, n;
int preorder[10001];

int main() {
    scanf("%d%d", &m, &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &preorder[i]);
        visit.insert(preorder[i]);
    }

    for (int v = 0; v < m; v++) {
        int a, b;
        scanf("%d%d", &a, &b);

        int f1 = 0, f2 = 0;
        if (visit.find(a) == visit.end()) {
            f1 = 1;
        }
        if (visit.find(b) == visit.end()) {
            f2 = 2;
        }
        int flag = f1 + f2;
        int x;
        if (flag == 0) {
            for (int i = 0; i < n; i++) {
                x = preorder[i];
                if ((a < x && b > x) || (a > x && b < x) || a == x || b == x) {
                    break;
                }
            }
            if (a == x) {
                printf("%d is an ancestor of %d.\n", x, b);
            } else if (b == x) {
                printf("%d is an ancestor of %d.\n", x, a);
            } else {
                printf("LCA of %d and %d is %d.\n", a, b, x);
            }
        } else if (flag == 1) {
            printf("ERROR: %d is not found.\n", a);
        } else if (flag == 2) {
            printf("ERROR: %d is not found.\n", b);
        } else if (flag == 3) {
            printf("ERROR: %d and %d are not found.\n", a, b);
        }
    }


    return 0;
}