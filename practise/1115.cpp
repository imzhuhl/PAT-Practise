#include <iostream>
using namespace std;

struct Node {
    int value;
    int level;
    Node *left, *right;
}node[1001];

int N;
int top = 1;
int alllev[1001] = {0};
int maxlevel;

void insert(Node *root, Node *na) {
    Node *p = root;
    Node *fa;
    while (true) {
        fa = p;
        if (na->value <= p->value) {
            p = p->left;
            if (p == nullptr) {
                fa->left = na;
                break;
            }
        }
        else {
            p = p->right;
            if (p == nullptr) {
                fa->right = na;
                break;
            }
        }
    }

    na->level = fa->level + 1;
    alllev[na->level]++;
    if (maxlevel < na->level) maxlevel = na->level;
    return;
}

int main() {
    scanf("%d", &N);
    Node *root = &node[0];
    int val;
    scanf("%d", &val);
    root->value = val;
    root->level = 0;
    root->left = root->right = nullptr;
    alllev[0] = 1;
    maxlevel = 0;
    for (int i = 1; i < N; i++) {
        int val;
        scanf("%d", &val);
        Node *na = &node[top++];
        na->value = val;
        na->right = na->left = nullptr;
        insert(root, na);
    }

    printf("%d + %d = %d\n", alllev[maxlevel], alllev[maxlevel - 1], alllev[maxlevel] + alllev[maxlevel-1]);

    return 0;
}