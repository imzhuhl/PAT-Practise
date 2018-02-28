#include <iostream>
#include <map>
using namespace std;

int M, N;
map<int, int> rst;

int main() {
    cin >> M >> N;

    int maxcount = 0;
    int key = -1;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            int x;
            cin >> x;
            if (rst.find(x) != rst.end()) {
                rst[x]++;
            } else {
                rst[x] = 1;
            }
            if (maxcount < rst[x]) {
                maxcount = rst[x];
                key = x;
            }
        }
    }
    // 输入的时候就要开始统计，省去下面的开销，否则超时
    // map<int, int>::iterator it = rst.begin();
    // for (; it!= rst.end(); it++) {
    //     if (it->second > maxcount) {
    //         maxcount = it->second;
    //         key = it->first;
    //     }
    // }

    printf("%d\n", key);

    return 0;
}