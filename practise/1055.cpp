#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

struct People{
    char name[10];
    int age;
    int net;
}people[100001];

int n, k;

bool cmp(People &a, People &b) {
    if (a.net == b.net) {
        if (a.age == b.age) {
            if (strcmp(a.name, b.name) < 0) {
                return true;
            }
            return false;
        }
        return a.age < b.age;
    }
    return a.net > b.net;
}

int main() {
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%s %d %d", people[i].name, &people[i].age, &people[i].net);
    }
    sort(people, people + n, cmp);

    for (int i = 1; i <= k; i++) {
        int qk, amin, amax;
        scanf("%d%d%d", &qk, &amin, &amax);
        printf("Case #%d:\n", i);
        int cnt = 0;
        for (int j = 0; j < n; j++) {
            if (people[j].age >= amin && people[j].age <= amax) {
                cnt++;
                printf("%s %d %d\n", people[j].name, people[j].age, people[j].net);
            }
            if (cnt >= qk) break;
        }
        if (cnt == 0) {
            printf("None\n");
        }
    }


    return 0;
}