#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int ori[100001], aft[100001];
vector<int> rst;
int maxv = 0;

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &ori[i]);
        aft[i] = ori[i];
    }
    sort(aft, aft + n);

    for (int i = 0; i < n; i++) {
        if (aft[i] == ori[i] && ori[i] > maxv) {
            rst.push_back(ori[i]);
        }
        if (ori[i] > maxv) {
            maxv = ori[i];
        }
    }

    int len = rst.size();
    printf("%d\n", len);
    for (int i = 0; i < len; i++) {
        if (i) printf(" ");
        printf("%d", rst[i]);
    }
    printf("\n");

    return 0;
}