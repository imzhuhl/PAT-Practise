#include <iostream>

using namespace std;

int main() {
    long double a, b, c;
    int T;


    cin >> T;
    for (int i = 1; i <= T; i++) {
        cin >> a >> b >> c;
        bool r = a + b > c;
        if (r) {
            printf("Case #%d: true\n", i);
        } else {
            printf("Case #%d: false\n", i);
        }

    }

    return 0;
}