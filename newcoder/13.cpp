#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int msize, n;
    cin >> msize >> n;

    if (msize < 2) msize = 2;

    for (int i = msize; ; i++) {
        int flag = 0;
        int num = sqrt(msize);
        for (int j = 2; j <= num; j++) {
            if (i % j == 0) {
                flag = 1;
                break;
            }
        }
        if (flag == 0) {
            msize = i;
            break;
        }
    }

    int hashtbl[10000];
    int x;
    int hashv;
    for (int i = 0; i < n; i++) {
        cin >> x;
        hashv = x % msize;
        int c = 1;
        int idx = hashv;
        while (hashtbl[idx] == 1 && c < msize) {
            idx = (hashv + c * c) % msize;
            c++;
        }
        if (c == msize) {
            printf("-");
        } else {
            hashtbl[idx] = 1;
            printf("%d", idx);
        }
        if (i == n - 1) {
            printf("\n");
        } else {
            printf(" ");
        }
    }


    return 0;
}