#include <iostream>
#include <map>
#include <vector>
#include <cctype>
#include <algorithm>
#include <cstring>
using namespace std;

struct Rst {
    char sch[10];
    int score;
    int num;
} rst[100001];

int n;
map<string, int> school;
vector<map<string, int> > idsc;
int top = 0;

bool cmp(Rst &a, Rst &b) {
    if (a.score == b.score) {
        if (a.num == b.num) {
            int x = strcmp(a.sch, b.sch);
            if (x > 0) {
                return false;
            } else {
                return true;
            }
        }
        return a.num < b.num;
    }
    return a.score > b.score;
}

int main() {
    scanf("%d", &n);
    idsc.resize(n);

    char a[10], c[10];
    int b;
    for (int i = 0; i < n; i++) {
        scanf("%s %d %s", a, &b, c);
        string as = a;
        string cs = c;
        for (int j = 0; j < cs.size(); j++) {
            cs[j] = tolower(cs[j]);
        }

        int schid = -1;
        if (school.find(cs) == school.end()) {
            school[cs] = top;
            schid = top;
            top++;
        } else {
            schid = school[cs];
        }

        idsc[schid].insert(pair<string, int>(as, b)); 
        
    }

    map<string, int>::iterator it = school.begin(), pit;
    int v = 0;
    for (; it != school.end(); it++, v++) {
        int id = it->second;
        // cout << it->first << ":" << endl;
        double toscore = 0.0;
        for (pit = idsc[id].begin(); pit != idsc[id].end(); pit++) {
            if ((pit->first)[0] == 'T') {
                toscore += pit->second * 1.5;
            } else if ((pit->first)[0] == 'B') {
                toscore += pit->second / 1.5;
            } else {
                toscore += pit->second;
            }
        }
        // printf("%d\n", (int) toscore);

        strcpy(rst[v].sch, it->first.c_str());
        rst[v].score = (int) toscore;
        rst[v].num = idsc[id].size();
    }

    sort(rst, rst + v, cmp);

    int rank = 1;
    int curr = rst[0].score;
    printf("%d\n", v);
    for (int i = 0; i < v; i++) {
        if (curr != rst[i].score) {
            curr = rst[i].score;
            rank = i + 1;
        }
        printf("%d %s %d %d\n", rank, rst[i].sch, rst[i].score, rst[i]. num);
    }

    return 0;
}