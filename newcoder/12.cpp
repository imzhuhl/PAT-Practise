#include <iostream>

using namespace std;

int xway() {
    int N;
    cin >> N;
    getchar();
    
    char s[100][300];
    int len[100];
    for (int i = 0; i < N; ++i) {
        gets(s[i]);
        len[i] = strlen(s[i]);
    }

}

int main() {
    int N;
    cin >> N;

    string s[100];
    int minlen = 256;

    getchar();

    for (int i = 0; i < N; i++) {
        getline(cin, s[i]);
    }

    for (int i = 1; i < N; i++) {
        int samelen = 0;
        int a = s[i - 1].length();
        int b = s[i].length();
        while (s[i - 1][a - 1] == s[i][b - 1]) {
            a--;
            b--;
            samelen++;
            if (a == 0 || b == 0) break;
        }
        if (minlen > samelen) {
            minlen = samelen;
        }
        if (minlen == 0) break;
    }

    if (minlen == 0) {
        printf("nai\n");
        return 0;
    }
    int len = s[0].length();
    for (int i = minlen; i > 0; i--) {
        printf("%c", s[0][len - i]);
    }
    printf("\n");

    return 0;
}