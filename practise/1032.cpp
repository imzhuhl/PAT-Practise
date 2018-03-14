#include <iostream>
#include <vector>
using namespace std;

int nxt[100001];
int visit[100001] = {0};
int id1, id2, n;

int main() {
    scanf("%d %d %d", &id1, &id2, &n);
    for (int i = 0; i < n; i++) {
        int a, b;
        char v;
        scanf("%d %c %d", &a, &v, &b);
        nxt[a] = b;
    }
    
    for (int i = id1; i != -1; i = nxt[i]) {
        visit[i] = 1;
    }
    for (int i = id2; i != -1; i = nxt[i]) {
        if (visit[i] == 1) {
            printf("%05d\n", i);
            return 0;
        }
    }

    printf("-1\n");

    return 0;
}