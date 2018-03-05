#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N;
string all[10005];

bool cmp(string &a, string &b) {
    return a + b < b + a;
}

int main() {
    scanf("%d", &N);
    int len = 0;
    for (int i = 0; i < N; i++) {
        cin >> all[i];
    }
    sort(all, all + N, cmp);
    string rst;
    for (int i = 0; i < N; i++) {
        rst += all[i];
    }
    int i;
    for (i = 0; i < N; i++) {
        if (rst[i] != '0') break;
    }
    if (i >= N)
        printf("0");
    else 
        printf("%s", rst.c_str() + i);
    printf("\n");

    return 0;
}