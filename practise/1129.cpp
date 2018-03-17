#include <iostream>
#include <set>
#include <algorithm>
#include <vector>
using namespace std;

struct Node {
    int val, cnt;
    Node(int a, int b): val(a), cnt(b){}
    bool operator < (const Node &a) const {
        if (cnt == a.cnt) return val < a.val;
        return cnt > a.cnt;
    }
};

int book[50001] = {0};

int main() {
    int n, k;
    set<Node> info;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        if (i) {
            printf("%d:", x);
            int cnt = 0;
            set<Node>::iterator it = info.begin();
            for (; it != info.end() && cnt < k; it++, cnt++) {
                printf(" %d", it->val);
            }
            printf("\n");
        }

        set<Node>::iterator it = info.find(Node(x, book[x]));
        book[x]++;
        if (it == info.end()) {
            info.insert(Node(x, book[x]));
        } else {
            info.erase(it);
            info.insert(Node(x, book[x]));
        }

        
    }

    return 0;
}