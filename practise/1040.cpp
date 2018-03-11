#include <iostream>
using namespace std;

int main() {
    char all[1001];
    int len = 0;
    char c = getchar();
    while (c != '\n') {
        all[len++] = c;
        c = getchar();
    }

    int maxsum = 1;
    for (int i = 0; i < len - 1; i++) {
        int left, right;
        int sum = 0;
        left = i;
        right = i + 1;
        while (all[left] == all[right]) {
            sum += 2;
            left--;
            right++;
            if (left < 0 || right >= len)
                break;
        }
        if (maxsum < sum) maxsum = sum;

        sum = 1;
        left = i - 1;
        right = i + 1;
        if (left < 0) continue;
        while (all[left] == all[right]) {
            sum += 2;
            left--;
            right++;
            if (left < 0 || right >= len)
                break;
        }
        if (maxsum < sum) maxsum = sum;
    }

    printf("%d\n", maxsum);
    return 0;
}