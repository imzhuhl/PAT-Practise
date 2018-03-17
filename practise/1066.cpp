#include <iostream>
#include <algorithm>
using namespace std;

struct Node {
    int val, height;
    Node *left, *right;
} node[22];
int total = 0;
int n;

int height(Node *p) {
    if (p == 0) 
        return -1;
    else
        return p->height;
}

Node *LL(Node *root) {
    Node *lp = root->left;
    root->left = lp->right;
    lp->right = root;
    root->height = max(height(root->left), height(root->right)) + 1;
    lp->height = max(height(lp->left), height(lp->right)) + 1;
    return lp;
}

Node *RR(Node *root) {
    Node *rp = root->right;
    root->right = rp->left;
    rp->left = root;
    root->height = max(height(root->left), height(root->right)) + 1;
    rp->height = max(height(rp->left), height(rp->right)) + 1;
    return rp;
}

Node *LR(Node *root) {
    root->left = RR(root->left);
    return LL(root);
}

Node *RL(Node *root) {
    root->right = LL(root->right);
    return RR(root);
}


Node* insert(Node *root, int val) {
    if (root == 0) {
        root = &node[total++];
        root->val = val;
        root->height = 0;
        root->left = root->right = 0;
    } else if (root->val > val) {
        root->left = insert(root->left, val);
        if (height(root->left) - height(root->right) == 2) {
            root = (val < root->left->val) ? LL(root) : LR(root);
        }
    } else if (root->val < val) {
        root->right = insert(root->right, val);
        if (height(root->right) - height(root->left) == 2) {
            root = (val > root->right->val) ? RR(root) : RL(root);
        }
    }

    root->height = max(height(root->left), height(root->right)) + 1;
    return root;

}

int main() {
    scanf("%d", &n);
    Node *root = 0;
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        root = insert(root, x);
    }
    printf("%d\n", root->val);
    return 0;
}