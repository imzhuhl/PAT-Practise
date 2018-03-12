#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string origin;
string temp;
int k;

int main() {
    cin >> origin >> k;
    int cnt = k;
    for (int i = 0; i < k; i++) {
        temp = origin;
        reverse(temp.begin(), temp.end());
        if (temp == origin) {
            cnt = i;
            break;
        }

        int flag = 0;
        int len = origin.size();
        for (int j = 0; j < len; j++) {
            int a = origin[j] - '0';
            int b = temp[j] - '0';
            int sum = a + b + flag;
            if (sum >= 10) {
                sum -= 10;
                flag = 1;
            } else {
                flag = 0;
            }
            origin[j] = sum + '0';
        }
        if (flag == 1) {
            origin += '1';
        }
        reverse(origin.begin(), origin.end());
    }
    cout << origin << endl << cnt << endl;

    return 0;
}