#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, M, K;
    cin >> N >> M >> K;

    int score[40000][3];
    int prefer[40000][5];
    int rec[100];
    for (int i = 0; i < M; i++) {
        cin >> rec[i];
    }

    for (int i = 0; i < N; i++) {
        cin >> score[i][1] >> score[i][2];
        score[i][0] = score[i][1] + score[i][2];
        for (int j = 0; j < K; j++) {
            cin >> prefer[i][j];
        }
    }

    vector<int> school[100];
    vector<int> same;
    int rest = N;
    while (rest) {
        int max[2] = {0};
        for (int i = 0; i < N; i++) {
            if (max[0] < score[i][0]) {
                max[0] = score[i][0];
                max[1] = score[i][1];
                same.clear();
                same.push_back(i);
            } else if (max[0] == score[i][0] && max[1] < score[i][1]) {
                max[1] = score[i][1];
                same.clear();
                same.push_back(i);
            } else if (max[0] == score[i][0] && max[1] == score[i][1]) {
                same.push_back(i);
            }
        }
        int stunum = same.size();
        rest -= stunum;

        for (int i = 0; i < same.size(); i++){
            score[same[i]][0] = 0;
        }

        for (int i = 0; i < K; i++) {
            for (int j = 0; j < M; j++) {
                if (rec[j] > 0) {
                    for (int l = 0; l < stunum; l++) {
                        if (same[l] == -1) continue;
                        int schoolid = prefer[same[l]][i];
                        if (schoolid == j) {
                            school[j].push_back(same[l]);
                            same[l] = -1;
                            rec[j]--;
                        }
                    }
                }
                
            }
        }
        
    }


    for (int i = 0; i < M; i++) {
        int stunum = school[i].size();
        if(stunum == 0) {
            printf("\n");
        } else {
            sort(school[i].begin(), school[i].end());
            for (int j = 0; j < stunum; j++) {
                if (j) printf(" ");
                printf("%d", school[i][j]);
            }
            printf("\n");
        }
    }

    return 0;
}