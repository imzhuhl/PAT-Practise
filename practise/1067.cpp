#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n;
    int all[100001];
    int posi[100001];
    int index = 1;
    int zaddr = -1;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        all[i] = x;
        posi[x] = i;
    }

    // for (int i = 0; i < n; i++) {
    //     printf("%d %d\n", all[i], mark[i]);
    // }
    zaddr = posi[0];
    int sum = 0;
    while (true) {
        if (zaddr != 0) {
            int idx = posi[zaddr];
            swap(all[zaddr], all[idx]);
            posi[0] = idx;
            posi[zaddr] = zaddr;
            sum++;
        } else {
            while (all[index] == index) {
                index++;
                if (index >= n) break;
            }
            if (index >= n) break;
            int num = all[index];
            swap(all[0], all[index]);
            posi[0] = index;
            posi[num] = 0;
            sum++;
        }
        zaddr = posi[0];
        // printf("zaddr: %d\n", zaddr);
    }

    printf("%d\n", sum);

    return 0;
}