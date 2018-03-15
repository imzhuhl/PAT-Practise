#include <iostream>
using namespace std;

int main() {
    int n;
    long double sum = 0.0;
    long double currsum = 0.0;
    long double info[100001];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        long double x;
        scanf("%Lf", &x);
        info[i] = x;
        currsum += x;
        sum += currsum;
    }

    long double rstsum = 0.0;
    for (int i = 0; i < n; i++) {
        // printf("sum: %lf\n", sum);
        rstsum += sum;
        sum = sum - info[i] * (n - i);
    }


    printf("%.2Lf\n", rstsum);

    return 0;
}