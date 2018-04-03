#include <iostream>
#include <sstream>
using namespace std;

int main() {
    int d, n;
    scanf("%d%d", &d, &n);

    string a, b;
    stringstream out;
    a = d + '0';
    for (int i = 1; i < n; i++) {
        char x = a[0];
        int cnt = 1;
        for (int j = 1; j < a.size(); j++) {
            if (x == a[j]) {
                cnt++;
            } else {
                b += x;
                out.str("");
                out << cnt;
                b += out.str();
                cnt = 1;
                x = a[j];
            }
        }
        b += x;
        out.str("");
        out << cnt;
        b += out.str();
        a.clear();
        a = b;
        b.clear();
    }

    cout << a <<endl;

    return 0;
}