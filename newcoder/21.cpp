#include <iostream>
#include <set>

using namespace std;

int main() {
    int N;
    cin >> N;
    set<int> st[55];

    for (int i = 1; i <= N; i++) {
        int x;
        cin >> x;
        for (int j = 0; j < x; j++) {
            int num;
            cin >> num;
            st[i].insert(num);
        }
    }

    int k;
    cin >> k;
    for (int i = 0; i < k; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        int count = 0;
        set<int>::iterator it1 = st[a].begin(), it2 = st[b].begin();

        while (it1 != st[a].end() && it2 != st[b].end()) {
            if (*it1 == *it2) {
                count++;
                it1++;
                it2++;
            } else if (*it1 < *it2) {
                it1++;
            } else {
                it2++;
            }
        }
        float result = count * 100.0 / (st[a].size() + st[b].size() - count);
        printf("%.1f%%\n", result);
    }

    return 0;
}