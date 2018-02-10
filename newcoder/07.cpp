#include <cmath>
#include <iostream>
#include <string>

using namespace std;

int main() {
    int N;
    cin >> N;

    int start = 2;
    int maxlen = 0;
    int startnum = -1;

    for (; start < sqrt(N); start++) {
        int len = 0;
        int i = start;
        int num = N;
        while (num % i == 0) {
            num = num / i;
            i++;
            len++;
        }
        if (len > maxlen) {
            startnum = i - len;
            maxlen = len;
        }
    }
    if (maxlen == 0) {
        maxlen = 1;
        startnum = N;
    }
    cout << maxlen << endl;
    for (int i = 0; i < maxlen; i++) {
        if (i == maxlen - 1) {
            cout << startnum++ << endl;
        } else {
            cout << startnum++ << "*";
        }
    }
    return 0;
}