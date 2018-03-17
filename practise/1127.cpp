#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct Node {
    int val;
    Node *left, *right;
} node[31];
int top = 0;

int n;
int inorder[31];
int postorder[31];

Node* build(int instart, int inend, int poststart, int postend) {
    if (instart > inend)
        return 0;

    int v = instart;
    while (inorder[v] != postorder[postend]) v++;
    Node *p = &node[top++];
    p->val = inorder[v];
    p->left = build(instart, v - 1, poststart, poststart + v - instart - 1);
    p->right = build(v + 1, inend, poststart + v - instart, postend - 1);
    return p;

}

void bfs(Node *root) {
    vector<Node *> va, vb;
    int cnt = 0;
    int dir = 1;
    printf("%d", root->val);
    if (root->left != 0) va.push_back(root->left);
    if (root->right != 0) va.push_back(root->right);
    while (true) {
        for (int i = 0; i < va.size(); i++) {
            Node *p = va[i];
            // printf(" %d", p->val);
            if (p->left != 0) {
                vb.push_back(p->left);
            }
            if (p->right != 0) {
                vb.push_back(p->right);
            }
        }

        if (dir == -1) reverse(va.begin(), va.end());
        dir = -dir;
        for (int i = 0; i < va.size(); i++) {
            printf(" %d", va[i]->val);
        }

        if (vb.empty()) {
            break;
        } else {
            va.clear();
            va = vb;
            vb.clear();
        }
    }

}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &inorder[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &postorder[i]);
    }

    for (int i = 0; i < 31; i++) {
        node[i].left = node[i].right = 0;
    }

    Node *root = build(0, n - 1, 0, n - 1);
    bfs(root);
    printf("\n");

    return 0;
}