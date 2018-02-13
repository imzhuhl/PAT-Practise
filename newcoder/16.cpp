#include <iostream>
#include <vector>

using namespace std;

int main() {
    int np, ng;
    cin >> np >> ng;

    int val[1000];
    int order[1000];
    vector<int> av, bv;
    int level[1000];

    for (int i = 0; i < np; i++) {
        cin >> val[i];
    }
    for (int i = 0; i < np; i++) {
        int x;
        cin >> x;
        av.push_back(x);
    }
    
    int score = 0;
    while (av.size() != 1) {
        int len = av.size();
        int circle = len % ng == 0 ? (len / ng) : (len / ng + 1);
        for (int i = 0; i < circle; i++) {
            int wid = ng;
            int max = 0;
            int maxidx = -1;
            if (i == circle - 1 && len % ng != 0) {
                wid = len % ng;
            }
            int base = i * ng;
            for (int j = 0; j < wid; j++) {
                int value = val[av[base + j]];
                if (value > max) {
                    maxidx = av[base + j];
                    max = value;
                }
            }
            bv.push_back(maxidx);
            for (int j = 0; j < wid; j++) {
                if (av[base + j] == maxidx) {
                    continue;
                }
                level[av[base + j]] = score;
            }

        }
        av.clear();
        for (int i = 0; i < bv.size(); i++) {
            av.push_back(bv[i]);
        }
        bv.clear();
        score++;
    }
    level[av[0]] = score;

    int rst[1000];
    int rank = 1;
    int num = 0;
    for (int i = 0; i < np; i++) {
        for (int j = 0; j < np; j++) {
            if (level[j] == score) {
                rst[j] = rank;
                num++;
            }
        }
        rank += num;
        num = 0;
        score--;
    }

    for (int i = 0; i < np; i++) {
        if (i) printf(" ");
        printf("%d", rst[i]);
    }
    puts("");

    return 0;
}