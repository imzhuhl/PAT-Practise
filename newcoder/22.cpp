#include <iostream>
#include <algorithm>
using namespace std;

int rst[10005];
int a[10005];
int N;
int p = 0;

void getrst(int root) {
    if (root > N) {
        return;
    }
    int left = root * 2, right = root * 2 + 1;
    getrst(left);
    rst[root] = a[p++];
    getrst(right);
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    sort(a, a + N);
    getrst(1);

    for (int i = 1; i <= N; i++) {
        if (i != 1) printf(" ");
        printf("%d", rst[i]);
    }
    printf("\n");

    return 0;
}