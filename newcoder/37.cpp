#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int all[100005];

int main() {
    cin >> N >> M;
    int size = 0;
    for (int i = 0; i < N; i++) {
        cin >> all[i];
        if (all[i] <= M) {
            size++;
        }
    }

    sort(all, all + N);

    int left = 0, right = size - 1;
    while (left <= right) {
        if (all[left] + all[right] == M) {
            break;
        } else if (all[left] + all[right] > M) {
            right--;
        } else {
            left++;
        }
    }

    // printf("%d %d\n", left, right);
    if (left < right) {
        printf("%d %d\n", all[left], all[right]);
    } else {
        printf("No Solution\n");
    }

    return 0;
}