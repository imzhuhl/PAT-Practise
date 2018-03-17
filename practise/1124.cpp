#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;

int main() {
    int m, n, s;
    scanf("%d%d%d", &m, &n, &s);
    vector<string> all;
    set<string> have;
    all.resize(m + 1);

    for (int i = 1; i <= m; i++) {
        string name;
        cin >> name;
        all[i] = name;
    }

    bool mark = false;
    int cnt = 0;
    for (int i = s; i <= m; i++) {
        if (i == s) {
            cout << all[i] << endl;
            have.insert(all[i]);
            mark = true;
        } else if (cnt == n) {
            cnt = 0;
            while (have.find(all[i]) != have.end()) {
                i++;
                if (i > m) break;
            }
            if (i > m) break;
            have.insert(all[i]);
            cout << all[i] << endl;
        }
        cnt++;
    }

    if (mark == false) {
        printf("Keep going...\n");
    }


    return 0;
}