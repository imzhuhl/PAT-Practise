#include <iostream>
#include <cstring>
#include <vector>
#include <string>

using namespace std;

int main() {
    vector<string> str;
    string s;
    vector<int> count;
    char c = '0';
    while (c != '\n') {
        c = getchar();
        bool have = false;
        s = "";
        if ((c >= '0' && c <= '9') ||(c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
            while ((c >= '0' && c <= '9') ||(c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
                if (c >= 'A' && c <= 'Z') {
                    c = c + 32;
                }
                s += c;
                c = getchar();
            }
            for (int i = 0; i < str.size(); i++) {
                if (str[i] == s) {
                    count[i]++;
                    have = true;
                }
            }
            if (!have) {
                str.push_back(s);
                count.push_back(1);

            }
        }
    }

    int max = -1;
    int idx = -1;
    for (int i = 0; i < str.size(); i++) {
        if (count[i] > max) {
            max = count[i];
            idx = i;
        } else if (count[i] == max) {
            idx = str[idx] < str[i] ? idx : i;
            max = count[idx];
        }
    }
    printf("%s %d\n", str[idx].c_str(), max);

    return 0;
}