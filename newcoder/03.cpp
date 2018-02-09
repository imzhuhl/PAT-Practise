#include <iostream>
#include <math.h>
using namespace std;

void findway(int arr[], int i, int &c) {
    if (arr[i] != -1) {
        c++;
        findway(arr, arr[i], c);
    }
    return;
}

int main() {
    int N;
    double P, r;

    cin >> N >> P >> r;
    int prenode[N];
    for (int i = 0; i < N; i++) {
        cin >> prenode[i];
    }

    int max = 0;
    int cost = 0;
    int count = 0;
    for (int i = 0; i < N; i++) {
        findway(prenode, i, cost);
        if (cost > max) {
            max = cost;
            count = 1;
        } else if (cost == max) {
            count++;
        }
        cost = 0;
    }
    P = pow((r/100) + 1, max) * P;
    printf("%.2lf %d\n", P, count);
}