#include <iostream>

using namespace std;

bool mark[100005];
int a[100005];

int main() {
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

    int total = 0;

    for (int i = 0; i < N; i++) {
        int have = 0;
        int x = a[i];
        int k = 0;
        for (; mark[x] == false; k++) {
            if (x == 0) {
                have = 1;
            }
            mark[x] = true;
            x = a[x];
        }
        if (have) {
            total += k - 1;
        } else if (k > 1) {
            total += k + 1;
        }
    }

    printf("%d\n", total);

    return 0;
}