#include <cstring>
#include <iostream>
#include <string>
using namespace std;

int main() {
    int g1, g2, s1, s2, k1, k2;
    scanf("%d.%d.%d %d.%d.%d", &g1, &s1, &k1, &g2, &s2, &k2);

    int k = k1 + k2;
    int s = s1 + s2;
    int g = g1 + g2;

    if (k >= 29) {
        k = k % 29;
        s += 1;
    }
    if (s >= 17) {
        s = s % 17;
        g += 1;
    }

    printf("%d.%d.%d\n", g, s, k);

    return 0;
}