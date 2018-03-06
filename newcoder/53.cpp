#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, L, H;
vector<int> sage[100000];
int tsage = 0;
vector<int> noblemen[100000];
int tnoble = 0;
vector<int> foolmen[100000];
int tfool = 0;
vector<int> smallmen[100000];
int tsmall = 0;

bool sagecmp(vector<int> &a, vector<int> &b) {
    if (a[1] + a[2] < b[1] + b[2])
        return false;
    else if (a[1] + a[2] > b[1] + b[2])
        return true;
    else {
        if (a[1] < b[1]) return false;
        else if (a[1] > b[1]) return true;
        else return a[0] < b[0];
    }
}

int main() {
    scanf("%d%d%d", &N, &L, &H);
    int total = 0;
    for (int i = 0; i < N; i++) {
        int id, vgrade, tgrade;
        scanf("%d%d%d", &id, &vgrade, &tgrade);
        if (vgrade < L || tgrade < L) 
            continue;
        if (vgrade >= H && tgrade >= H) {
            sage[tsage].push_back(id);
            sage[tsage].push_back(vgrade);
            sage[tsage].push_back(tgrade);
            tsage++;
        } else if (tgrade < H && vgrade >= H) {
            noblemen[tnoble].push_back(id);
            noblemen[tnoble].push_back(vgrade);
            noblemen[tnoble].push_back(tgrade);
            tnoble++;
        } else if (vgrade < H && tgrade < H && vgrade >= tgrade) {
            foolmen[tfool].push_back(id);
            foolmen[tfool].push_back(vgrade);
            foolmen[tfool].push_back(tgrade);
            tfool++;
        } else {
            smallmen[tsmall].push_back(id);
            smallmen[tsmall].push_back(vgrade);
            smallmen[tsmall].push_back(tgrade);
            tsmall++;
        }
        total++; 
    }

    printf("%d\n", total);
    sort(sage, sage + tsage, sagecmp);
    for (int i = 0; i < tsage; i++) {
        printf("%08d %d %d\n", sage[i][0], sage[i][1], sage[i][2]);
        
    }
    sort(noblemen, noblemen + tnoble, sagecmp);
    for (int i = 0; i < tnoble; i++) {
        printf("%08d %d %d\n", noblemen[i][0], noblemen[i][1], noblemen[i][2]);
        
    }
    sort(foolmen, foolmen + tfool, sagecmp);
    for (int i = 0; i < tfool; i++) {
        printf("%08d %d %d\n", foolmen[i][0], foolmen[i][1], foolmen[i][2]);
        
    }
    sort(smallmen, smallmen + tsmall, sagecmp);
    for (int i = 0; i < tsmall; i++) {
        printf("%08d %d %d\n", smallmen[i][0], smallmen[i][1], smallmen[i][2]);
        
    }

    return 0;
}