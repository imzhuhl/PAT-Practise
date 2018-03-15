#include <iostream>
#include <string>
using namespace std;


string lowdig[13] = {"tret", "jan", "feb", "mar", "apr", 
                        "may", "jun", "jly", "aug", 
                        "sep", "oct", "nov", "dec"};
string highdig[13] = {"", "tam", "hel", "maa", "huh", 
                        "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};


int main() {
    int n;
    scanf("%d", &n);
    getchar();
    for (int i = 0; i < n; i++) {
        string a;
        string h, l;
        int d = -1;
        getline(cin, a, '\n');
        if (a[0] >= '0' && a[0] <= '9') {
            d = stoi(a);
        } else {
            h = a;
        }

        if (d != -1) {
            int x = d / 13;
            int y = d % 13;
            if (x != 0) {
                printf("%s", highdig[x].c_str());
                if (y != 0) 
                    printf(" %s", lowdig[y].c_str());                    
            }
            else {
                printf("%s", lowdig[y].c_str());
            }
            printf("\n");
        } else {
            int x = -1, y = -1;
            if (h.size() == 4) {
                printf("0\n");
                continue;
            }
            if (h.size() > 3) {
                l = h.substr(4, 3);
                h = h.substr(0, 3);
                for (int i = 1; i < 13; i++) {
                    if (h == highdig[i])  {
                        x = i;
                        break;
                    }
                }
                for (int i = 0; i < 13; i++) {
                    if (l == lowdig[i]) {
                        y = i;
                        break;
                    }
                }
                printf("%d\n", x * 13 + y);
            } else {
                for (int i = 0; i < 13; i++) {
                    if (h == lowdig[i]) {
                        y = i;
                        break;
                    } else if (h == highdig[i]) {
                        x = i;
                        break;
                    }
                }
                if (x == -1) {
                    printf("%d\n", y);
                } else {
                    printf("%d\n", x * 13);
                }
            }


        }

        
    }

    return 0;
}
