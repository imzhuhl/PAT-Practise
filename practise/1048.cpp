#include <iostream>

using namespace std;

int N, M;
int coin[505] = {0};

int main() {
    scanf("%d%d", &N, &M);
    for (int i = 0; i < N; i++) {
        int v;
        scanf("%d", &v);
        coin[v]++;
    }

    bool find = false;
    int a, b;
    for (int i = 1; i + i <= M; i++) {
        if (coin[i] != 0) {
            int sec = M - i;
            if (sec > 500) continue;
            if (sec != i) {
                if (coin[sec] != 0) {
                    find = true;
                    a = i;
                    b = sec;
                    break;
                }
            } else {
                if (coin[i] >= 2) {
                    find = true;
                    a = b = i;
                    break;
                }
            }
            
        }
    }
    if (find) {
        printf("%d %d\n", a, b);
    } else {
        printf("No Solution\n");
    }
    return 0;
}