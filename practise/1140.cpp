#include <iostream>
using namespace std;

int main() {
    int d, n;
    scanf("%d%d", &d, &n);

    string a, b;
    a = d + '0';
    for (int i = 1; i < n; i++) {
        char x = a[0];
        int cnt = 1;
        for (int j = 1; j < a.size(); j++) {
            if (x == a[j]) {
                cnt++;
            } else {
                b += x;
                b += to_string(cnt);
                cnt = 1;
                x = a[j];
            }
        }
        b += x;
        b += to_string(cnt);
        a.clear();
        a = b;
        b.clear();
    }

    cout << a <<endl;

    return 0;
}