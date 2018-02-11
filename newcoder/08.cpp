#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int first, N;

    cin >> first >> N;

    int arr[N][3];
    for (int i = 0; i < N; i++) {
        cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
    }
    int res_list[N][2];
    int rmv_list[N][2];
    int absval[10001];
    int reslen = 0, rmvlen = 0, vallen = 0;
    int curr = first;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (curr == arr[j][0]) {
                int value = arr[j][1] >= 0 ? arr[j][1] : -arr[j][1];
                if (absval[value] != 0) {
                    rmv_list[rmvlen][0] = arr[j][0];
                    rmv_list[rmvlen][1] = arr[j][1];
                    rmvlen++;
                } else {
                    absval[value] = 1;
                    res_list[reslen][0] = arr[j][0];
                    res_list[reslen][1] = arr[j][1];
                    reslen++;
                }
                curr = arr[j][2];
                break;
            }
        }
        if (curr == -1)
            break;
    }

    int i;
    for (i = 0; i < reslen - 1; i++) {
        printf("%05d %d %05d\n", res_list[i][0], res_list[i][1], res_list[i + 1][0]);
    }
    printf("%05d %d -1\n", res_list[i][0], res_list[i][1]);

    for (i = 0; i < rmvlen - 1; i++) {
        printf("%05d %d %05d\n", rmv_list[i][0], rmv_list[i][1], rmv_list[i + 1][0]);
    }
    printf("%05d %d -1\n", rmv_list[i][0], rmv_list[i][1]);

    return 0;
}