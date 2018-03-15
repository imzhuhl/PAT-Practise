#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

vector<int> all;
int matrix[10005][10005] = {0};

int main() {
    int n, x;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        all.push_back(x);
    }
    sort(all.begin(), all.end(), greater<int>());

    int row, col;
    for (int i = sqrt(n); i >= 1; i--) {
        if (n % i == 0) {
            col = i;
            row = n / col;
            break;
        }
    }
    // printf("%d %d\n", row, col);

    int i = 0, j = 0;
    int right = 1, down = 0, left = 0, up = 0;
    for (int k = 0; k < n; ) {
        matrix[i][j] = all[k];
        if (k == n - 1) break;
        if (right == 1) {
            if (j + 1 < col && matrix[i][j + 1] == 0) {
                j++;
                k++;
            } else {
                right = 0;
                down = 1;
            }
        } else if (down == 1) {
            if (i + 1 < row && matrix[i + 1][j] == 0) {
                i++;
                k++;
            } else {
                down = 0;
                left = 1;
            }
        } else if (left == 1) {
            if (j - 1 >= 0 && matrix[i][j - 1] == 0) {
                j--;
                k++;
            } else {
                left = 0;
                up = 1;
            }
        } else if (up == 1) {
            if (i - 1 >= 0 && matrix[i - 1][j] == 0) {
                i--;
                k++;
            } else {
                up = 0;
                right = 1;
            }
        }
    }

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (j) printf(" ");
            printf("%d", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}