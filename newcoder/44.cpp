#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

int N;
int people[10005][3];
map<int, int> arrv;
int tablenum, viptabnum;
int tabletime[105];
int isviptable[105];
queue<int> ordwait;
queue<int> vipwait;
int currtime = 8 * 3600;

void print(int id, int tabid) {
    int t = people[id][0];
    int h = t / 3600;
    int m = t % 3600 / 60;
    int s = t % 3600 % 60;
    printf("%02d:%02d:%02d ", h, m, s);
    int n = tabletime[tabid] > t ? tabletime[tabid] : t;
    h = n / 3600;
    m = n % 3600 / 60;
    s = n % 3600 % 60;
    printf("%02d:%02d:%02d ", h, m, s);
    printf("%.0lf", round((n - t) * 1.0 / 60));
}

void insertqueue(int id) {
    if (people[id][2] == 1) {
        vipwait.push(id);
    } else {
        ordwait.push(id);
    }
    currtime = people[id][0];
}

void selecttable() {
    int id;
    int tabid = -1;
    if (vipwait.empty()) {
        id = ordwait.front();
        for (int i = 1; i <= tablenum; i++) {
            if (currtime >= tabletime[i]) {
                printf("select: %d\n", tabletime[i]);
                tabid = i;
                break;
            }
        }
        if (tabid != -1) {
            ordwait.pop();
        }
    } else if (ordwait.empty()) {
        id = vipwait.front();
        for (int i = 1; i <= tablenum; i++) {
            if (currtime >= tabletime[i]) {
                tabid = i;
                break;
            }
        }
        if (tabid != -1) vipwait.pop();
    } else {
        id = vipwait.front();
        for (int i = 1; i <= tablenum; i++) {
            if (isviptable[i] && currtime >= tabletime[i]) {
                tabid = i;
            }
        }
        if (tabid != -1) {
            vipwait.pop();
        } else {
            if (vipwait.front() < ordwait.front()) {
                id = vipwait.front();
                for (int i = 1; i <= tablenum; i++) {
                    if (currtime >= tabletime[i]) {
                        tabid = i;
                        break;
                    }
                }
                if (tabid != -1)
                    vipwait.pop();
            } else {
                id = ordwait.front();
                for (int i = 1; i <= tablenum; i++) {
                    if (currtime >= tabletime[i]) {
                        tabid = i;
                        break;
                    }
                }
                if (tabid != -1)
                    ordwait.pop();
            }
        }
    }
    // printf("%d\n", tabid);
    if (tabid != -1) {
        print(id, tabid);
        tabletime[tabid] += people[id][1];
    }
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        int h, m, s, playtime, vip;
        scanf("%d:%d:%d", &h, &m, &s);
        scanf("%d%d", &playtime, &vip);
        people[i][0] = h * 3600 + m * 60 + s;
        people[i][1] = playtime * 60;
        people[i][2] = vip;
        arrv[people[i][0]] = i;
    }
    cin >> tablenum >> viptabnum;
    for (int i = 1; i <= viptabnum; i++) {
        int tabid;
        cin >> tabid;
        isviptable[tabid] = 1;
    }  

    map<int, int>::iterator it = arrv.begin();

    while (true) {
        if (it != arrv.end()) {
            insertqueue(it->second);
        }
        if (ordwait.empty() && vipwait.empty()) {
            break;
        }
        selecttable();
    }

}