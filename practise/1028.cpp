#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

struct Stu{
    int id;
    char name[10];
    int grade;
}stu[100001];

bool idcmp(Stu &a, Stu &b) {
    return a.id < b.id;
}

bool namecmp(Stu &a, Stu &b) {
    int ret = strcmp(a.name, b.name);
    if (ret > 0) {
        return false;
    } else if (ret == 0) {
        return a.id < b.id;
    } else {
        return true;
    }
}

bool gradecmp(Stu &a, Stu &b) {
    if (a.grade == b.grade) 
        return a.id < b.id;
    return a.grade < b.grade;
}

int main() {
    int n, c;
    scanf("%d%d", &n, &c);
    for (int i = 0; i < n; i++) {
        scanf("%d %s %d", &stu[i].id, stu[i].name, &stu[i].grade);
    }

    if (c == 1) {
        sort(stu, stu + n, idcmp);
    } else if (c == 2) {
        sort(stu, stu + n, namecmp);
    } else {
        sort(stu, stu + n, gradecmp);        
    }

    for (int i = 0; i < n; i++) {
        printf("%06d %s %d\n", stu[i].id, stu[i].name, stu[i].grade);
    }


    return 0;
}