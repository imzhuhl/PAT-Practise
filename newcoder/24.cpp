#include <iostream>
#include <algorithm>
using namespace std;

struct node {
    int val;
    int height;
    node *lchild;
    node *rchild;
};
node all[22];
int total;

int height(node *root) {
    return root ? root->height : -1;
}

node *LL(node *n) {
    node *nw = n->lchild;
    n->lchild = nw->rchild;
    nw->rchild = n;
    n->height = max(height(n->lchild), height(n->rchild)) + 1;
    nw->height = max(height(nw->lchild), height(nw->rchild)) + 1;
    return nw;
}
node *RR(node *n) {
    node *nw = n->rchild;
    n->rchild = nw->lchild;
    nw->lchild = n;
    n->height = max(height(n->lchild), height(n->rchild)) + 1;
    nw->height = max(height(nw->lchild), height(nw->rchild)) + 1;
    return nw;
}
node *LR(node *n) {
    n->lchild = RR(n->lchild);
    return LL(n);
}
node *RL(node *n) {
    n->rchild = LL(n->rchild);
    return RR(n);
}

node *insert(node *root, int val) {
    if (root == 0) {
        root = &all[total++];
        root->val = val;
        root->lchild = root->rchild = 0;
        root->height = 0;
    } else if (val < root->val) {
        root->lchild = insert(root->lchild, val);
        if (height(root->lchild) - height(root->rchild) == 2) {
            root = (val < root->lchild->val) ? LL(root) : LR(root);
        }
    } else {
        root->rchild = insert(root->rchild, val);
        if (height(root->rchild) - height(root->lchild) == 2) {
            root = (val > root->rchild->val) ? RR(root) : RL(root);
        }
    }
    root->height = max(height(root->lchild), height(root->rchild)) + 1;
    return root;
}



int main() {
    int N;
    cin >> N;
    node *root = 0;
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        root = insert(root, x);
    }
    printf("%d\n", root->val);
    return 0;
}