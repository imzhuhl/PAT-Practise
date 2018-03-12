#include <iostream>
#include <cstring>
using namespace std;

int main() {
    int mark[10] = {0};
    char origin[25];
    scanf("%s", origin);
    int len = strlen(origin);

    int flag = 0;
    for (int i = len - 1; i >= 0; i--) {
        int a = origin[i] - '0';
        mark[a]++;
        a = a * 2 + flag;
        if (a >= 10) {
            flag = 1;
            a = a - 10;
        } else {
            flag = 0;
        }
        mark[a]--;
        origin[i] = a + '0';
    }
    int flag1 = 0;
    for (int i = 1; i <= 9; i++) {
        if (mark[i] != 0) {
            flag1 = 1;
            break;
        }
    }
    if (flag != 0 || flag1 != 0) {
        printf("No\n");
    } else {
        printf("Yes\n");
    }
    if (flag != 0) printf("1");
    printf("%s\n", origin);
    return 0;
}