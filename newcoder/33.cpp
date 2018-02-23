#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    int all[100005];
    int sum = 0;
    bool mark = false;
    map<int, int> mp;
    int minval = 0x7fffffff;
    int l = 1, r = 0;
    for (int i = 1; i <= N; i++) {
        cin >> all[i];
        sum += all[i];
        r++;
        if (sum < M) {
            ;
        } else if (sum == M) {
            mark = true;
            printf("%d-%d\n", l, r);
        } else if (sum > M) {
            while (sum > M) {
                if (minval > sum - M) {
                    minval = sum - M;
                    mp.clear();
                    mp[l] = r;
                } else if (minval == sum - M) {
                    mp[l] = r;
                }
                sum -= all[l];
                l++;
            }
            if (sum == M) {
                mark = true;
                printf("%d-%d\n", l, r);
            }
        }
        
    }

    if (!mark) {
        map<int, int>::iterator it;
        for (it = mp.begin(); it != mp.end(); it++) {
            printf("%d-%d\n", it->first, it->second);
        }
    }

    return 0;
}