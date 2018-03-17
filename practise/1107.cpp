#include <iostream>
#include <algorithm>
using namespace std;

int father[1001];
int people[1001];
int n;

int Find(int a) {
    while (father[a] != a) {
        father[a] = father[father[a]];
        a = father[a];
    }
    return a;
}

void Union(int a, int b) {
    int fa = Find(a);
    int fb = Find(b);
    if (fa != fb) {
        father[fa] = fb;
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= 1000; i++) {
        father[i] = i;
    }
    for (int i = 1; i <= n; i++) {
        int v, id;
        scanf("%d: ", &v);
        scanf("%d", &id);
        people[i] = id;
        for (int j = 1; j < v; j++) {
            int oid;
            scanf("%d", &oid);
            Union(id, oid);
        }
    }

    int visit[1001] = {0};
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        int x = Find(people[i]);
        if (visit[x] == 0) cnt++;
        visit[x]++;
    }

    sort(visit, visit + 1001, greater<int>());
    printf("%d\n", cnt);
    for (int i = 0; i < cnt; i++) {
        if (i) printf(" ");
        printf("%d", visit[i]);
    }
    printf("\n");
    return 0;
}