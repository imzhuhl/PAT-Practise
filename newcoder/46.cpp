#include <iostream>
using namespace std;

int s1, s2, N;
int all[100005];
int mark[100005];

int main() {
    scanf("%d%d%d", &s1, &s2, &N);
    for (int i = 0; i < N; i++) {
        int addr, next;
        char a[10];
        scanf("%d%s%d", &addr, a, &next);
        all[addr] = next;
    }

    int curr = s1;
    while (curr != -1) {
        // printf("%d\n", curr);
        mark[curr] = 1;
        curr = all[curr];
    }

    curr = s2;
    int start = -1;
    bool find = false;
    while (curr != -1) {
        if (mark[curr] == 1 && find == false) {
            find = true;
            start = curr;
        }
        if (mark[curr] != 1) {
            find = false;
            start = -1;
        }
        curr = all[curr];
    }

    if (find){
        printf("%d\n", start);
    } else {
        printf("-1\n");
    }

    return 0;
}