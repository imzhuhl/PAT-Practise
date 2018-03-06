#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdlib>
using namespace std;

char num[4];
int rst;

bool decrease(char &a, char &b) {
    return a > b;
}

int main() {
    scanf("%d", &rst);
    while (true) {
        sprintf(num, "%04d", rst);
        sort(num, num + 4);
        int smaller, bigger;
        sscanf(num, "%d", &smaller);
        reverse(num, num + 4);
        sscanf(num, "%d", &bigger);
        rst = bigger - smaller;
        printf("%04d - %04d = %04d\n", bigger, smaller, rst);
        if (rst == 0 || rst == 6174) {
            break;
        }
    }
    return 0;
}