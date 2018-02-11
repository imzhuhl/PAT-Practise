#include <iostream>
#include <algorithm>

using namespace std;

int vindex = 0;

void mid_scan(int tree[][3], int root, int arr[]) {
    if (tree[root][0] != -1) {
        mid_scan(tree, tree[root][0], arr);
    }
    tree[root][2] = arr[vindex++];
    if (tree[root][1] != -1) {
        mid_scan(tree, tree[root][1], arr);
    }
    return;
}


int main() {
    int N;
    cin >> N;
    int tree[N][3];
    int arr[N];
    for (int i = 0; i < N; i++) {
        cin >> tree[i][0] >> tree[i][1];
    }
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + N);

    mid_scan(tree, 0, arr);

    int nodenum = 0;
    int queue[N];
    int idx = 1;
    int p = 1;
    while (p < N) {
        printf("%d ", tree[nodenum][2]);
        if (tree[nodenum][0] != -1) {
            queue[idx++] = tree[nodenum][0];
        }
        if (tree[nodenum][1] != -1) {
            queue[idx++] = tree[nodenum][1];
        }
        nodenum = queue[p++];
    }
    printf("%d\n", tree[nodenum][2]);


}