#include <iostream>
#include <string>
#include <cstring>
#include <cctype>
using namespace std;

string week[7] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};

int main() {
    char a[60], b[60];
    int alen, blen;

    scanf("%s%s", a, b);
    // printf("%s\n%s\n", a, b);
    alen = strlen(a);
    blen = strlen(b);
    int aidx = 0, bidx = 0;
    for (int i = 0; i < alen && i < blen; i++) {
        if (a[i] >= 'A' && a[i] <= 'G' && a[i] == b[i]) {
            aidx = i;
            break;
        }
    }
    for (int i = aidx + 1; i < alen && blen; i++) {
        if ((isdigit(a[i]) || (a[i] >= 'A' && a[i] <= 'N')) && a[i] == b[i]) {
            bidx = i;
            break;
        }
    }
    
    char c[60], d[60];
    scanf("%s%s", c, d);
    int clen = strlen(c);
    int dlen = strlen(d);
    int cidx = 0;
    for (int i = 0; i < clen && i < dlen; i++) {
        if (isalpha(c[i]) && c[i] == d[i]) {
            cidx = i;
            break;
        }
    }
    int w = a[aidx] - 'A';
    int h = isdigit(a[bidx]) ? a[bidx] - '0' : a[bidx] - 'A' + 10;

    printf("%s %02d:%02d\n", week[w].c_str(), h, cidx);

    return 0;
}
