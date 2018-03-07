#include <iostream>
using namespace std;

bool isprime(int msize) {
    if (msize == 1) return false;
    for (int i = 2; i * i <= msize; i++) {
        if (msize % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int msize, N;
    int mark[10010] = {0};
    scanf("%d%d", &msize, &N);
    while (isprime(msize) == false) {
        msize++;
    }
    // printf("%d\n", msize);
    for (int i = 0; i < N; i++) {
        int key;
        scanf("%d", &key);
        int idx = key % msize;
        if (i) printf(" ");
        if (mark[idx] != 1) {
            mark[idx] = 1;
            printf("%d", idx);
        } else {
            int flag = 0;
            for (int j = 1; j < msize; j++) {
                idx = (key + j * j) % msize;
                if (mark[idx] != 1) {
                    mark[idx] = 1;
                    flag = 1;
                    printf("%d", idx);
                    break;
                }
            }
            if (flag == 0) {
                printf("-");
            }
        }
    }
    printf("\n");

    return 0;
}
