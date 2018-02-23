#include <iostream>

using namespace std;

int main() {
    int K;
    cin >> K;
    int order[55];
    int rst[55];
    for (int i = 1; i <= 54; i++) {
        cin >> order[i];
    }

    for (int i = 1; i <= 54; i++) {
        int x = order[i];
        for (int j = 1; j < K; j++) {
            x = order[x];
        }
        rst[x] = i;
    }

    for (int i = 1; i <= 54; i++) {
        if (i != 1) {
            printf(" ");
        }
        int v = rst[i];
        switch((v - 1) / 13) {
        case 0:
            printf("S");
            break;
        case 1:
            printf("H");
            break;
        case 2:
            printf("C");
            break;
        case 3:
            printf("D");
            break;
        default:
            printf("J");
            break;
        }
        printf("%d", (v - 1) % 13 + 1);
    }
    printf("\n");

    return 0;
}