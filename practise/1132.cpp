#include <iostream>
#include <cstring>
#include <string>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        string num;
        cin >> num;
        string a = num.substr(0, num.size() / 2);
        string b = num.substr(num.size()/2, num.size());
        int x = stoi(num);
        int y = stoi(a);
        int z = stoi(b);
        if (y == 0 || z == 0) {
            printf("No\n");
            continue;
        }
        if (x % (y * z) == 0) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }

    return 0;
}