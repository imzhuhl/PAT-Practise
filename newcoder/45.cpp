#include <iostream>
#include <string>
using namespace std;

int main() {
    string a;
    cin >> a;
    int len = a.size();
    int l1 = (len + 2) / 3;
    int rest = len - l1 - l1;
    for (int i = 0; i < l1 - 1; i++) {
        printf("%c", a[i]);
        for (int j = 0; j < rest; j++) {
            printf(" ");
        }
        printf("%c\n", a[len - 1 - i]);
    }
    for (int i = l1 - 1; i < l1 + rest + 1; i++) {
        printf("%c", a[i]);
    }
    printf("\n");
}