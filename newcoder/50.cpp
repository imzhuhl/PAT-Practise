#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

int N, K;
vector<int> stu[175761];
int have[175761] = {0};
int top = 0;

int main() {
    scanf("%d%d", &N, &K);
    for (int i = 0; i < K; i++) {
        int courseid, regnum;
        scanf("%d%d", &courseid, &regnum);
        for (int j = 0; j < regnum; j++) {
            char name[6];
            scanf("%s", name);
            int hashval = (name[0] - 'A') * 6760 + (name[1] - 'A') * 260 + (name[2] - 'A') * 10 + (name[3] - '0');
            stu[hashval].push_back(courseid);
            have[hashval] = 1;
        }
    }
    for (int i = 0; i < N; i++) {
        char name[6];
        scanf("%s", name);
        int hashval = (name[0] - 'A') * 6760 + (name[1] - 'A') * 260 + (name[2] - 'A') * 10 + (name[3] - '0');
        if (have[hashval] != 1) {
            printf("%s 0\n", name);
            continue;
        }
        int len = stu[hashval].size();
        sort(stu[hashval].begin(), stu[hashval].end());
        printf("%s %d", name, len);
        for (int j = 0; j < len; j++) {
            printf(" %d", stu[hashval][j]);
        }
        printf("\n");
    }


    return 0;
}