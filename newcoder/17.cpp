#include <iostream>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

int big[400][400];
int bignum[400];
int stack[100005];
int top = 0;
int N;

int calculate(int &top) {
    int sum = 0;
    for (int i = 0; i < 400; i++) {
        if (sum + bignum[i] < (top + 1) / 2)
            sum += bignum[i];
        else {
            for (int j = 0; j < 400; j++) {
                sum += big[i][j];
                if (sum >= (top + 1) / 2) {
                    return j + i * 400;
                }
            }
        }
    }
    return 0;
}

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        char a[15];
        scanf("%s", a);
        if (strcmp(a, "Pop") == 0) {
            if (top == 0) {
                printf("Invalid\n");
            } else {
                int x = stack[top - 1];
                top--;
                big[x/400][x%400] -= 1;
                bignum[x/400] -= 1;
                printf("%d\n", x);
            }
        } else if (strcmp(a, "PeekMedian") == 0) {
            if (top == 0) {
                printf("Invalid\n");
            } else {
                int v = calculate(top);
                printf("%d\n", v);
            }
        } else if (strcmp(a, "Push") == 0) {
            int x;
            scanf("%d", &x);
            stack[top++] = x;
            big[x/400][x%400] += 1;
            bignum[x/400] += 1;
        }
    }

    return 0;
}