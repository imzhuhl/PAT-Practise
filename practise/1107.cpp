#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int course[1001] = {0};
vector<int> father;

int Find(int a) {
    while (a != father[a]) {
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

bool cmp(int &a, int &b) {
    return a > b;
}

int main() {
    scanf("%d", &N);
    father.resize(N + 1);
    for (int i = 0; i <= N; i++) {
        father[i] = i;
    }
    for (int i = 1; i <= N; i++) {
        int hobnum;
        scanf("%d:", &hobnum);
        for (int j = 0; j < hobnum; j++) {
            int x;
            scanf("%d", &x);
            if (course[x] == 0) {
                course[x] = i;
            }
            Union(i, course[x]);
        }
    }

    int clu[1005] = {0};
    int count = 0;
    for (int i = 1; i <= N; i++) {
        int x = Find(i);
        if (clu[x] == 0) count++;
        clu[x]++;
    }
    sort(clu, clu + 1001, cmp);
    printf("%d\n", count);
    for (int i = 0; i < count; i++) {
        if (i) printf(" ");
        printf("%d", clu[i]);
    }
    printf("\n");

    return 0;
}