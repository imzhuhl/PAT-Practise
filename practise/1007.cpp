#include <iostream>
using namespace std;

int main() {
    int n;
    int all[10001];
    int currsum = 0, maxsum = -1;
    int maxa = 0, maxb = 0;
    int curra = 0;
    bool mark = false;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &all[i]);
        if (mark == false && all[i] >= 0) mark = true;
        currsum += all[i];
        if (currsum > maxsum) {
            maxsum = currsum;
            maxa = curra;
            maxb = i;
        } else if (currsum < 0) {
            curra = i + 1;
            currsum = 0;
        }
    }

    if (mark) {
        printf("%d %d %d\n", maxsum, all[maxa], all[maxb]);
    } else {
        printf("0 %d %d\n", all[0], all[n - 1]);
    }

    return 0;
}