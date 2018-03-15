#include <iostream>
#include <vector>
using namespace std;

int main() {
    int a, b;
    scanf("%d%d", &a, &b);
    vector<char> rst;
    int cnt = 0, flag = 0;
    int c = a + b;

    if (c < 0) {
        flag = 1;
        c = -c;
    } else if (c == 0) {
        printf("0\n");
        return 0;
    }
    while (c != 0) {
        if (cnt == 3) {
            cnt = 0;
            rst.push_back(',');
        }
        rst.push_back((c % 10 + '0'));
        cnt++;
        c = c / 10;
    }

    if (flag == 1) printf("-");
    for (int i = rst.size() - 1; i >= 0; i--) {
        printf("%c", rst[i]);
    }
    printf("\n");

    return 0;
}

// #include <iostream>
// using namespace std;
// int main() {
//     int a, b;
//     cin >> a >> b;
//     string s = to_string(a + b);
//     int len = s.length();
//     for (int i = 0; i < len; i++) {
//         cout << s[i];
//         if (s[i] == '-') continue;
//         if ((i + 1) % 3 == len % 3 && i != len - 1) cout << ",";
//     }
//     return 0;
// }