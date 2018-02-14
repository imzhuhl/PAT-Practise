#include <cstring>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

string standard(char *s, int n) {
    int k = 0;
    string answer;
    bool mark = false;

    for (int i = 0; s[i]; i++) {
        if (s[i] == '.') {
            mark = true;
        } else {
            if (!mark) {
                k++;
            }
            if (answer == "" && s[i] == '0') {
                k--;
            } else {
                answer += s[i];
            }
        }
    }
    while (answer.size() < n) {
        answer += '0';
    }
    if (answer.size() > n) {
        answer = answer.substr(0, n);
    }
    mark = true;
    for (int i = 0; i < n; i++) {
        if (answer[i] != '0') {
            mark = false;
        }
    }
    if (mark) {
        k = 0;
    }
    ostringstream out;
    out << "0." << answer << "*10^" << k;
    return out.str();
    
}

int main() {
    int n;
    char s[205];

    scanf("%d%s", &n, s);
    string a = standard(s, n);
    scanf("%s", s);
    string b = standard(s, n);

    if (a == b) {
        printf("YES %s\n", a.c_str());
    } else {
        printf("NO %s %s\n", a.c_str(), b.c_str());
    }


    return 0;
}