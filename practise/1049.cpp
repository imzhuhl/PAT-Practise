#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    int num[32];
    int top = 0;
    int a = n;
    while (a != 0) {
        num[top++] = a % 10;
        a /= 10;
    }
    reverse(num, num + top);
    // for (int i =0; i < top; i++) {
    //     printf("%d ", num[i]);
    // }
    
    int count = 0;
    int x;
    for (int i = 0; i < top; i++) {
        x = num[i];
        int v = 0;
        if (x == 0) {
            for (int j = 0; j < top; j++) {
                if (j == i) {
                    v -= 1;
                    continue;
                } else if (j < i) {
                    v = v * 10 + num[j];
                } else {
                    v = v * 10 + 9;
                }
            }
        } else if (x == 1) {
            for (int j = 0; j < top; j++) {
                if (j == i) {
                    continue;
                } else {
                    v = v * 10 + num[j];
                }
            }
        } else {
            for (int j = 0; j < top; j++) {
                if (j == i) {
                    continue;
                } else if (j < i) {
                    v = v * 10 + num[j];
                } else {
                    v = v * 10 + 9;
                }
            }
        }
        // printf("%d\n", v + 1);
        count += v + 1;
    }

    printf("%d\n", count);

    return 0;
}