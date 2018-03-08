#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

int people[10000] = {0};
vector<int> fam;
int info[1001][4] = {0};

struct Data {
    int minid, num, est, area;
}fd[1005];

struct Node {
    int id, num;
    double est, area;
    bool flag;
} ans[1005];

int Find(int id) {
    while (id != fam[id]) {
        id = fam[id];
    }
    return id;
}

void Union(int a, int b) {
    a = Find(a);
    b = Find(b);
    if (a != b)
        fam[a] = b;
}

bool cmp(Node &a, Node &b) {
    if (a.area != b.area) {
        return a.area > b.area;
    } else {
        return a.id < b.id;
    }
}

int main() {
    int N;
    scanf("%d", &N);
    fam.resize(N + 1);
    for (int i = 1; i <= N; i++) {
        fam[i] = i;
    }
    for (int i = 1; i <= N; i++) {
        int minpeo = 10000;
        int id;
        for (int j = 0; j < 3; j++) {
            scanf("%d", &id);
            // printf("%d ", id);
            if (id == -1) continue;
            if (people[id] == 0) {
                people[id] = i;
                fd[i].num++;
                if (minpeo > id) 
                    minpeo = id;
            }
            Union(i, people[id]);
        }
        int childnum;
        scanf("%d", &childnum);
        for (int j = 0; j < childnum; j++) {
            scanf("%d", &id);
            // printf("%d ", id);
            if (people[id] == 0) {
                people[id] = i;
                fd[i].num++;
                if (minpeo > id) 
                    minpeo = id;
            }
            Union(i, people[id]);
        }
        fd[i].minid = minpeo;
        scanf("%d%d", &fd[i].est, &fd[i].area);
    }

    // for (int i = 1; i <= N; i++) {
    //     printf("%d ", fam[i]);
    // }
    // printf("fdfdf\n");

    for (int i = 1; i <= N; i++) {
        int x = Find(i);
        if (ans[x].flag == false) {
            ans[x].id = fd[i].minid;
            ans[x].flag = true;
        }
        if (ans[x].id > fd[i].minid) 
            ans[x].id = fd[i].minid;
        ans[x].num += fd[i].num;
        ans[x].est += fd[i].est;
        ans[x].area += fd[i].area;
        
    }
    int cnt = 0;
    Node rst[1005];
    for (int i = 1; i <= N; i++) {
        if (ans[i].flag == true) {
            rst[cnt].id = ans[i].id;
            rst[cnt].num = ans[i].num;
            rst[cnt].est = ans[i].est / ans[i].num;
            rst[cnt].area = ans[i].area / ans[i].num;
            cnt++;
        }
    }
    sort(rst, rst + cnt, cmp);
    printf("%d\n", cnt);
    for (int i = 0; i < cnt; i++) {
        printf("%04d %d %.3lf %.3lf\n", rst[i].id, rst[i].num, rst[i].est, rst[i].area);
    }

    return 0;
}