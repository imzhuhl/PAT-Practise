#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool cmp(string a, string b) {
    return a + b < b + a;
}

int main() {
    vector<string> all;
    int n;
    string x;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        cin >> x;
        all.push_back(x);
    }
    
    sort(all.begin(), all.end(), cmp);
    int len = all.size();
    bool head = false;
    for (int i = 0; i < len; i++) {
        if (!head) {
            int x = stoi(all[i]);
            if (x != 0) {
                head = true;
                printf("%d", x);
            }
        } else { 
            printf("%s", all[i].c_str());
        }
        
    }
    if (head == false) printf("0");
    printf("\n");
}