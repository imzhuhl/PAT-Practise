#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int N, K, M;

int problem[6];
int rst[10005][10];

int main() {
    memset(rst, -1, sizeof(rst));
    cin >> N >> K >> M;

    for (int i = 1; i <= K; i++) {
        cin >> problem[i];
    }

    for (int i = 0; i < M; i++) {
        int userid, proid, score;
        cin >> userid >> proid >> score;
        if (score != -1) {
            rst[userid][0] = 1;
            if (rst[userid][proid] < score) {
                rst[userid][proid] = score;
            }
        } else {
            if (rst[userid][proid] < 0) {
                rst[userid][proid] = 0;
            }
        }
    }

    int info[10005][3];
    memset(info, -1, sizeof(info));

    for (int i = 1; i <= N; i++) {
        if (rst[i][0] == 1) {
            int sum = 0;
            int full = 0;
            for (int j = 1; j <= K; j++) {
                if (rst[i][j] != -1) {
                    if(rst[i][j] == problem[j])
                        full++;
                    sum += rst[i][j];
                }
            }
            info[i][0] = 1;
            info[i][1] = sum;
            info[i][2] = full;
        }
    }

    // find 
    int rank = 1;
    for (int i = 1; i <= N; i++) {
        int max = -1;
        vector<int> idx;
        for (int j = 1; j <= N; j++) {
            if (info[j][0] != 1) {
                continue;
            }
            if (max < info[j][1]) {
                max = info[j][1];
                idx.clear();
                idx.push_back(j);
            } else if (max == info[j][1]) {
                idx.push_back(j);
            }
        }

        for (int j = 0; j < idx.size(); j++) {
            int count = -1;
            int user = -1;
            for (int r = 0; r < idx.size(); r++) {
                int uid = idx[r];
                if (count < info[uid][2]) {
                    count = info[uid][2];
                    user = uid;
                }
            }
            printf("%d %05d %d", rank, user, info[user][1]);
            for (int r = 1; r <= K; r++) {
                if (rst[user][r] == -1) {
                    printf(" -");
                } else {
                    printf(" %d", rst[user][r]);
                }
            }
            printf("\n");
            info[user][0] = -1;
            info[user][1] = -1;
            info[user][2] = -1;
        }

        rank += idx.size();
    }

    return 0;
}