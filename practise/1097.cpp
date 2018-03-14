#include <iostream>
#include <vector>

using namespace std;

int head, n;
int nxt[100000];
int val[100000];
int mark[100000] = {0};

vector<int> output, relist;


int main() {
    scanf("%d%d", &head, &n);
    for (int i = 0; i < n; i++) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        nxt[a] = c;
        val[a] = b;
    }

    int p = head;
    while (p != -1) {
        int abv = val[p];
        if (abv < 0) abv = -abv;
        if (mark[abv] == 0) {
            mark[abv] = 1;
            output.push_back(p);
        } else {
            relist.push_back(p);
        }
        p = nxt[p];
    }

    printf("%05d %d ", output[0], val[output[0]]);
    for (int i = 1; i < output.size(); i++) {
        printf("%05d\n", output[i]);
        printf("%05d %d ", output[i], val[output[i]]);
    }
    printf("-1\n");

    if (relist.empty()) return 0;
    printf("%05d %d ", relist[0], val[relist[0]]);
    for (int i = 1; i < relist.size(); i++) {
        printf("%05d\n", relist[i]);
        printf("%05d %d ", relist[i], val[relist[i]]);
    }
    printf("-1\n");


    return 0;
}