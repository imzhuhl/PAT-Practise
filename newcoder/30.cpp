#include <iostream>
#include <map>
using namespace std;

int N;
map<int, int> rst;
int num[100005];
int len = 0;

int main() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        map<int, int>::iterator it = rst.find(x);
        if (it == rst.end()) {
            num[len++] = x;
            rst[x] = 1;
        } else {
            rst[x] += 1;
        }
    }
    
    for (int i = 0; i < len; i++) {
        int key = num[i];
        if (rst[key] == 1) {
            printf("%d\n", num[i]);
            return 0;
        }
    }

    printf("None\n");

    return 0;
}