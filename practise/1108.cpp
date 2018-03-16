#include <iostream>
#include <cstring>
using namespace std;

int main() {
    int n;
    char a[50], b[50];
    int cnt = 0;
    double sum = 0.0;
    double temp;

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        bool mark = true;
        scanf("%s", a);
        sscanf(a, "%lf", &temp);
        sprintf(b, "%.2lf", temp);
        // printf("%s %s", a, b);
        for (int j = 0; j < strlen(a); j++) {
            if (a[j] != b[j]) {
                mark = false;
                break;
            }
        }

        // if (mark && temp >= -1000 && temp <= 1000) {
        //     cnt++;
        //     sum += temp;
        // } else {
        //     printf("ERROR: %s is not a legal number\n", a);
        // }
        if (mark == false || temp < -1000 || temp > 1000) {
            printf("ERROR: %s is not a legal number\n", a);
            continue;
        } else {
            sum += temp;
            cnt++;
        }
    }

    if (cnt == 0) {
        printf("The average of 0 numbers is Undefined\n");
    } else if (cnt == 1) {
        printf("The average of 1 number is %.2lf\n", sum);
    } else {
        printf("The average of %d numbers is %.2lf\n", cnt, sum / cnt);
    }

    return 0;
}