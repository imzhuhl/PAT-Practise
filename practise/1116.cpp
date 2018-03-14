#include <iostream>

using namespace std;

int prime[10001] = {0};
int n;
int ranklist[10001] = {0};
int visit[10001] = {0};

void fillprime() {
    for (int i = 2; i <= n; i++) {
        bool is = true;
        for (int j = 2; j * j <= i; j++) {
            if (i % j == 0) {
                is = false;
                break;
            }
        }
        if (is == true) {
            prime[i] = 1;
        }
    }
}

int main() {
    scanf("%d", &n);
    fillprime();
    for (int i = 1; i <= n; i++) {
        int x;
        scanf("%d", &x);
        ranklist[x] = i;
    }
    int k;
    scanf("%d", &k);
    for (int i = 0; i < k; i++) {
        int x;
        scanf("%d", &x);
        int rank = ranklist[x];
        printf("%04d: ", x);
        if (rank == 0) {
            printf("Are you kidding?\n");
        } else {
            if (visit[x] == 1) {
                printf("Checked\n");
            } else {
                if (rank == 1) {
                    printf("Mystery Award\n");
                } else if (prime[rank] == 1) {
                    printf("Minion\n");
                } else {
                    printf("Chocolate\n");
                }
                visit[x] = 1;
            }
        }
        
    }
    
    return 0;
}