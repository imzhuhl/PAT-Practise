#include <iostream>
using namespace std;

int main() {
    int N, M;

    cin >> N >> M;
    int info[N+1][N+1];

    for (int i = 0; i < N+1; i++) {
        for (int j = 0; j < N+1; j++) {
            info[i][j] = 0;
        }
    }

    int id, k;
    for (int i = 0; i < M; i++) {
        cin >> id >> k;
        info[id][0] = k;
        for (int j = 1; j <= k; j++) {
            cin >> info[id][j];
        }
    }

    int max = 1;
    int level = 1;
    int stack[N];
    int top = 0;
    int gen[N+1];
    gen[1] = 1;
    stack[0] = 1;
    top++;
    int n, tm;
    while (top != 0) {
        n = stack[--top];
        tm = info[n][0];
        if (tm != 0) {
            level = gen[n];
            for (int j = 1; j <= tm; j++) {
                gen[info[n][j]] = level + 1;
                stack[top++] = info[n][j];
            }
        }
    }
    int count;
    for (int i = 1; i <= N; i++) {
        count = 0;
        for (int j = 1; j <= N; j++) {
            if(gen[j] == i) {
                count++;
            }
        }
        if (max < count) {
            max = count;
            level = i;
        }
    }
    cout << max << " " << level << endl;

    return 0;
}