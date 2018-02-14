#include <cstring>
#include <iostream>
#include <string>
using namespace std;

int main() {
    string str;
    cin >> str;

    int g1, g2, s1, s2, k1, k2;
    int idx1 = 0, idx2 = 0;
    idx1 = str.find(".");
    g1 = atoi(str.substr(0, idx1).c_str());
    str = str.substr(idx1 + 1, str.size());
    idx2 = str.find(".");
    s1 = atoi(str.substr(0, idx2).c_str());
    str = str.substr(idx2 + 1, str.size());
    k1 = atoi(str.c_str());

    cin >> str;
    idx1 = str.find(".");
    g2 = atoi(str.substr(0, idx1).c_str());
    str = str.substr(idx1 + 1, str.size());
    idx2 = str.find(".");
    s2 = atoi(str.substr(0, idx2).c_str());
    str = str.substr(idx2 + 1, str.size());
    k2 = atoi(str.c_str());

    int k = k1 + k2;
    int s = s1 + s2;
    int g = g1 + g2;

    if (k >= 29) {
        k = k % 29;
        s += 1;
    }
    if (s >= 17) {
        s = s % 17;
        g += 1;
    }

    printf("%d.%d.%d\n", g, s, k);

    return 0;
}