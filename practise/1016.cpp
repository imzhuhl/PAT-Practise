#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
#include <set>
#include <vector>
using namespace std;

struct Record{
    char name[22];
    int month, day, hour, minute;
    int status; // 0 off, 1 on
}rec[1001];
int top = 1;

int price[24];
int N;
int bill[501][2] = {0};
int bn = 0;
vector<char [22]> people;

bool cmp(Record &a, Record &b) {
    int r = strcmp(a.name, b.name);
    if (r > 0) {
        return false;
    } else if (r < 0) {
        return true;
    } else {
        if (a.month != b.month) {
            return a.month < b.month;
        } else if (a.day != b.day) {
            return a.day < b.day;
        } else if (a.hour != b.hour) {
            return a.hour < b.hour;
        } else {
            return a.minute < b.minute;
        }
    }
}

int main() {
    for (int i = 0; i < 24; i++) {
        scanf("%d", &price[i]);
    }
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%s", rec[top].name);
        people.push_back(rec[top].name);
        scanf("%d:%d:%d:%d", &rec[top].month, &rec[top].day, &rec[top].hour, &rec[top].minute);
        char a[10];
        scanf("%s", a);
        if (a[1] == 'n') {
            rec[top].status = 1;
        } else {
            rec[top].status = 0;
        }
        top++;
    }

    sort(rec + 1, rec + top, cmp);
    sort(people.begin(), people.end());

    printf("-------------\n");
    for (int i = 1; i < top; i++) {
        printf("%s ", rec[i].name);
        printf("%02d:%02d:%02d:%02d\n", rec[i].month, rec[i].day, rec[i].hour, rec[i].minute);
    }
    printf("------------\n");

    char currname[22];
    strcpy(currname, rec[0].name);
    int waitsta = 1;
    for (int i = 1; i < top - 1; i++) {
        if (strcmp(rec[i].name, rec[i + 1].name) == 0) {
            if (rec[i].status == 1 && rec[i + 1].status == 0) {
                bill[bn][0] = i;
                bill[bn][1] = i + 1;
                bn++;
                i++;
            } else if (rec[i].status == rec[i].status == 0) {
                i++;
            } else {
                continue;
            }
        } else {
            continue;
        }
    }

    int p = 0;
    for (int i = 0; i < people.size(); i++) {
        char name[22];
        strcpy(name, people[i]);
        Record *r1 = &rec[bill[p][0]];
        Record *r2;
        printf("%s %02d\n", name, r1->month);
        for (int j = p; j < bn; j++) {
            r1 = &rec[bill[j][0]];
            r2 = &rec[bill[j][1]];
            printf("%02d%02d%02d ", r1->day, r1->hour, r1->minute);
            printf("%02d%02d%02d ", r2->day, r2->hour, r2->minute);
            

        }

        
    }

    return 0;
}