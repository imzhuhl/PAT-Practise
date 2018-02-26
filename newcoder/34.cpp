#include <iostream>

using namespace std;

int main() {
    int N, M, L;
    int favo[205];
    int color[10005];
    int matrix[205][10005];
    cin >> N >> M;
    for (int i = 1; i <= M; i++) {
        cin >> favo[i];
    }
    cin >> L;
    for (int i = 1; i <= L; i++) {
        cin >> color[i];
    }

    int max = 0;
    for (int i = 1; i <= M; i++) {
        for (int j = 1; j <= L; j++) {
            if (favo[i] == color[j]) {
                matrix[i][j] = matrix[i][j - 1] + 1;
            } else {
                matrix[i][j] = matrix[i][j - 1];
            }
            if (matrix[i][j] < matrix[i - 1][j]) {
                matrix[i][j] = matrix[i - 1][j];
            }
            if (max < matrix[i][j]) {
                max = matrix[i][j];
            }
            // printf("%d ", matrix[i][j]);
        }
        // printf("\n");
    }

    printf("%d\n", matrix[M][L]);

    return 0;
}