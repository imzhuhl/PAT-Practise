#include <iostream>
using namespace std;

int bird[10001] = {0};
int father[10001];

int Find(int a) {
    while(a != father[a]) {
        father[a] = father[father[a]];
        a = father[a];
    }
    return a;
}

void Union(int a, int b) {
    a = Find(a);
    b = Find(b);
    if (a != b)
        father[a] = b;
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= 10000; i++) {
        father[i] = i;
    }
    for (int i = 0; i < n; i++) {
        int num, head;
        scanf("%d", &num);
        for (int j = 0; j < num; j++) {
            int id;
            scanf("%d", &id);
            if (bird[id] == 0) {
                bird[id] = 1;
            }
            if (j == 0) head = id;
            Union(head, id);
        }
    }

    int rst[10001] = {0};
    int cnt = 0;
    int sum = 0;
    for (int i = 1; i <= 10000; i++) {
        if (bird[i] == 1) {
            int x = Find(i);
            if (rst[x] == 0)
                cnt++;
            rst[x]++;
            sum++;
        }
    }
    printf("%d %d\n", cnt, sum);
    int query;
    scanf("%d", &query);
    for (int i = 0; i < query; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        if (Find(a) == Find(b)) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }

    return 0;
}