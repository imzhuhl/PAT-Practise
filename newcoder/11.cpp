#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int main() {
    int N, L;
    cin >> N >> L;

    int c;
    int x;
    vector<int> arr[1001];
    for (int i = 1; i <= N; i++) {
        cin >> c;
        for (int j = 0; j < c; j++) {
            cin >> x;
            arr[x].push_back(i);
        }
    }
    int k;
    cin >> k;
    int t[1001];
    for (int i = 0; i < k; i++) {
        memset(t, 0, sizeof(int) * 1001);
        cin >> x;
        t[x] = 1;
        queue<int> que;
        int max = 0;
        int levcnt = 1, curcnt;
        que.push(x);
        levcnt = 1;
        for (int j = 0; j < L; j++) {
            curcnt = 0;  
            while (levcnt > 0) {
                int n = que.front();
                for (int l = 0; l < arr[n].size(); l++) {
                    if (t[arr[n][l]] == 0) {
                        t[arr[n][l]] = 1;
                        que.push(arr[n][l]);
                        curcnt++;
                        max++;
                    }
                }
                que.pop();
                levcnt--;
            }
            levcnt = curcnt;
        }
        printf("%d\n", max);
    }


    
    

    return 0;
}