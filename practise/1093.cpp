#include <iostream>
#include <cstring>

using namespace std;

const int moder = 1000000007;

int main() {
    char all[100005];
    scanf("%s", all);
    int len = strlen(all);
    int a = 0;
    int sum = 0;
    int p = 0;
    for (int i = 0; i < len; i++) {
        if (all[i] == 'P') {
            p++;
        } else if (all[i] == 'A') {
            a += p;
            a = a % moder;
        } else {
            sum += a;
            sum = sum % moder;
        }
    }
    printf("%d\n", sum);

    return 0;
}