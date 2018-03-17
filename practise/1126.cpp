#include <iostream>
#include <vector>
using namespace std;

int visit[501] = {0};
vector<int> node[501];

void dfs(int a) {
    visit[a] = 1;
    for (int i = 0; i < node[a].size(); i++) {
        if (visit[node[a][i]] == 0) {
            dfs(node[a][i]);
        }
    }
}


int main() {
    int n, m;
    bool mark = true;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        node[a].push_back(b);
        node[b].push_back(a);
    }

    dfs(1);
    for (int i = 1; i <= n; i++) {
        if (visit[i] == 0) {
            mark = false;
        }
    }
    

    int status = 0;
    for (int i = 1; i <= n; i++) {
        int len = node[i].size();
        if (i != 1) printf(" ");
        printf("%d", len);
        if (len % 2 != 0) {
            status++;
        }
    }
    if (n != 0) printf("\n");
    if (mark && status == 0) {
        printf("Eulerian\n");
    } else if (mark && status == 2) {
        printf("Semi-Eulerian\n");
    } else {
        printf("Non-Eulerian\n");
    }


    return 0;
}