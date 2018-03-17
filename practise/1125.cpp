#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    vector<int> all;
    all.resize(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &all[i]);
    }
    sort(all.begin(), all.end());
    double sum = all[0];
    int seed = 2;
    for (int i = 1; i < n; i++) {
        sum = (sum + all[i] * 1.0) / seed;
        // printf("%d / %d : %lf\n", all[i], seed, sum);
    }
    int rst = sum;
    printf("%d\n", rst);

    return 0;
}