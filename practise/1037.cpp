#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(int a, int b) {
    return a > b;
}

int main() {
    int nc, np;
    vector<int> pos_con, neg_con, pos_pro, neg_pro;
    scanf("%d", &nc);
    for (int i = 0; i < nc; i++) {
        int x;
        scanf("%d", &x);
        if (x > 0) {
            pos_con.push_back(x);
        } else {
            x = -x;
            neg_con.push_back(x);
        }
    }
    scanf("%d", &np);
    for (int i = 0; i < np; i++) {
        int x;
        scanf("%d", &x);
        if (x > 0) {
            pos_pro.push_back(x);
        } else {
            x = -x;
            neg_pro.push_back(x);
        }
    }
    sort(pos_con.begin(), pos_con.end(), cmp);
    sort(neg_con.begin(), neg_con.end(), cmp);
    sort(pos_pro.begin(), pos_pro.end(), cmp);
    sort(neg_pro.begin(), neg_pro.end(), cmp);

    int sum = 0;
    int alen = pos_con.size();
    int blen = pos_pro.size();
    for (int i = 0; i < alen && i < blen; i++) {
        sum += pos_con[i] * pos_pro[i];
    }
    alen = neg_con.size();
    blen = neg_pro.size();
    for (int i = 0; i < alen && i < blen; i++) {
        sum += neg_con[i] * neg_pro[i];
    }

    printf("%d\n", sum);

    return 0;
}