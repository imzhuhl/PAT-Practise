#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
using namespace std;

int main() {
    int N, K;
    scanf("%d%d", &N, &K);
    char name[40005][5];
    set<string> info[2505];


    for (int i = 1; i <= N; i++) {
        int n;
        scanf("%s %d", name[i], &n);
        for (int j = 0; j < n; j++) {
            int x;
            cin >> x;
            info[x].insert(name[i]);
        }
    }

    for (int i = 1; i <= K; i++) {
        int len = info[i].size();
        printf("%d %d\n", i, len);
        
        set<string>::iterator it;

        for (it = info[i].begin(); it != info[i].end(); it++) {
            printf("%s\n", (*it).c_str());
        }
    }

    return 0;
}