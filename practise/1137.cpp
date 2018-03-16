#include <iostream>
#include <map>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;

struct Stu {
    char na[22];
    int ass, mid, fin, grade;
} stu[10001];

int top = 0;
map<string, int> qid;
map<int, string> qname;

bool cmp(Stu &a, Stu &b) {
    if (a.grade == b.grade) {
        if (strcmp(a.na, b.na) > 0) return false;
        else return true;
    }
    return a.grade > b.grade;
}

int main() {
    int p, m,n;
    scanf("%d%d%d", &p, &m, &n);

    string name;
    int score;
    for (int i = 0; i < p; i++) {
        cin >> name >> score;
        if (score >= 200 && score <= 900) {
            if (qid.find(name) == qid.end()) {
                sscanf(name.c_str(), "%s", stu[top].na);
                stu[top].ass = score;
                stu[top].mid = stu[top].fin = stu[top].grade = -1;
                qid[name] = top++;

            }
        }
    }

    for (int i = 0; i < m; i++) {
        cin >> name >> score;
        if (qid.find(name) != qid.end() && score <= 100) {
            int id = qid[name];
            stu[id].mid = score;
        }
    }

    for (int i = 0; i < n; i++) {
        cin >> name >> score;
        if (score > 100) continue;
        if (qid.find(name) != qid.end()) {
            int id = qid[name];
            stu[id].fin = score;
            if (stu[id].mid > score) {
                stu[id].grade = stu[id].mid * 0.4 + score * 0.6 + 0.5;
            } else {
                stu[id].grade = score;
            }
        }
    }

    sort(stu, stu + top, cmp);

    for (int i = 0; i < top; i++) {
        if (stu[i].grade < 60) continue;
        printf("%s %d %d %d %d\n", stu[i].na, stu[i].ass,
                                    stu[i].mid, stu[i].fin, stu[i].grade);

    }

    return 0;
}