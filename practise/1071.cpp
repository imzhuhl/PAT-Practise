#include <iostream>
#include <cctype>
#include <map>
#include <algorithm>
using namespace std;

map<string, int> rst;

int main() {
    char c;
    c = getchar();
    string s;
    while (c != '\n') {
        if (isalnum(c)) {
            if (isalpha(c))
                c = tolower(c);
            s += c;
        } else {
            if (!s.empty()) {
                rst[s]++;
                s.clear();
            }
        }
        c = getchar();
    }
    if (!s.empty())
        rst[s]++;

    map<string, int>::iterator it;
    string maxs;
    int maxc = 0;
    for (it = rst.begin(); it != rst.end(); it++) {
        if (maxc < it->second) {
            maxc = it->second;
            maxs = it->first;
        }
    }
    printf("%s %d\n", maxs.c_str(), maxc);

    return 0;
}