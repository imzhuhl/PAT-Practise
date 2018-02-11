#include <iostream>

using namespace std;

int method = 0;
int N;

int compare_rst(int arr[], int tmp_rst[]) {
    for (int i = 1; i <= N; i++) {
        if (arr[i] != tmp_rst[i]) {
            return 0;
        }
    } 
    return 1; 
}

void max_heapify(int arr[], int start, int end) {
    int dad = start;
    int son = start * 2;
    while (son <= end) {
        if (son + 1 <= end && arr[son] < arr[son + 1]) {
            son++;
        }
        if (arr[dad] > arr[son]) {
            return;
        } else {
            swap(arr[dad], arr[son]);
            dad = son;
            son = dad * 2;
        }
    }
}

int main() {
    cin >> N;
    int insert_arr[N + 1];
    int heap_arr[N + 1];
    int tmp_rst[N + 1];
    int x;
    for (int i = 1; i <= N; i++) {
        cin >> x;
        heap_arr[i] = x;
        insert_arr[i] = x;
    }
    for (int i = 1; i <= N; i++) {
        cin >> tmp_rst[i];
    }

    // insert first
    int i, j, tmp;
    for (i = 1; i <= N; i++) {
        if (compare_rst(insert_arr, tmp_rst) == 1) {
            method = 1;
        }
        tmp = insert_arr[i];
        for (j = i; j > 0; j--) {
            if (tmp < insert_arr[j]) {
                insert_arr[j + 1] = insert_arr[j];
            } else if (tmp > insert_arr[j]) {
                insert_arr[j + 1] = tmp;
                break;
            }
        }
        if (j == 0) {
            insert_arr[1] = tmp;
        }

        if (method == 1) {
            // print result
            printf("Insertion Sort\n");
            for (i = 1; i < N; i++) {
                printf("%d ", insert_arr[i]);
            }
            printf("%d\n", insert_arr[N]);
            return 0;
        }
    }

    // heap second
    for (i = N / 2; i >= 1; i--) {
        if (compare_rst(heap_arr, tmp_rst) == 1) {
            method = 2;
        }
        max_heapify(heap_arr, i, N);
        if (method == 2) break;
    }
    for (i = N; i > 1; i--) {
        if (method == 2 || compare_rst(heap_arr, tmp_rst) == 1) {
            method = 2;
        }
        swap(heap_arr[1], heap_arr[i]);
        max_heapify(heap_arr, 1, i - 1);
        if (method == 2) break;
    }

    if (method == 2) {
        printf("Heap Sort\n");
        for (i = 1; i < N; i++) {
            printf("%d ", heap_arr[i]);
        }
        printf("%d\n", heap_arr[N]);
    }

    return 0;
}