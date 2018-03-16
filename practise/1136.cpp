#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

bool palindromic(string &a) {
    int len = a.size();
    for (int i = 0; i < len / 2; i++) {
        if (a[i] != a[len - 1 - i]) {
            return false;
        }
    }
    return true;
}

void calcul(string &a, string &b, string &c) {
    int flag = 0;
    for (int i = 0; i < a.size(); i++) {
        int x = (a[i] - '0') + (b[i] - '0') + flag;
        if (x > 9) {
            x %= 10;
            flag = 1;
        } else {
            flag = 0;
        }
        c[i] = x + '0';
    }
    if (flag == 1) {
        c += '1';
    }
    reverse(c.begin(), c.end());
}

int main() {
    string ori, rev, tmp;
    cin >> ori;
    int cnt = 0;
    tmp = ori;
    //
    // rev = ori;
    // reverse(rev.begin(), rev.end());
    // calcul(ori, rev, tmp);
    //
    while (!palindromic(ori)) {
        cnt++;
        if (cnt > 10)
            break;
        rev = ori;
        reverse(rev.begin(), rev.end());
        calcul(ori, rev, tmp);
        cout << ori << " + " << rev << " = " << tmp << endl;
        ori = tmp;
    }

    // printf("%d\n", cnt);
    if (cnt <= 10) {
        cout << tmp << " is a palindromic number." << endl;
    } else {
        printf("Not found in 10 iterations.\n");
    }

    return 0;
}