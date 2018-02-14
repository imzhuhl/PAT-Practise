#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int calculate(int valarr[], int &top) {
    int sum = 0;
    for (int i = 0; i < 100005; i++) {
        sum += valarr[i];
        if (sum >= (top + 1) / 2) {
            return i;
        }
    }
    return 0;
}

int main() {
    int stack[100005];
    int top = 0;
    int valarr[100005];

    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        string a;
        cin >> a;
        if (a == "Pop") {
            if (top == 0) {
                printf("Invalid\n");
            } else {
                int x = stack[top - 1];
                top--;
                valarr[x] -= 1;
                printf("%d\n", x);
            }
        } else if (a == "PeekMedian") {
            if (top == 0) {
                printf("Invalid\n");
            } else {
                int v = calculate(valarr, top);
                printf("%d\n", v);
            }
        } else if (a == "Push") {
            int x;
            cin >> x;
            stack[top++] = x;
            valarr[x] += 1;
        }
    }

    return 0;
}