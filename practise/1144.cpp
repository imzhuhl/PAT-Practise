#include <iostream>
#include <set>
using namespace std;

int main() {
    int n;
    set<int> info;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        if (x > 0) {
            info.insert(x);
        }
    }
    set<int>::iterator it = info.begin();
    int rst = 1;
    for (int i = 1; it != info.end(); it++, i++) {
        rst = *it + 1;
        if (*it != i) {
            rst = i;
            break;
        }
    }

    printf("%d\n", rst);

    return 0;
}