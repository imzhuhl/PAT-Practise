#include <iostream>
#include <queue>
using namespace std;

struct node {
    node *left, *right;
    int val;
};

node all[35];
int top = 0;
int N;
int postorder[35];
int inorder[35];

node* build(int poststart, int postend, int instart, int inend) {
    if (poststart >= postend || instart >= inend) {
        return 0;
    }
    int val = postorder[postend - 1];
    int idx;
    for (int i = 0; i < N; i++) {
        if (inorder[i] == val) {
            idx = i;
            break;
        }
    } 
    node *root = &all[top++];
    root->val = val;
    // printf("%d %d %d %d %d\n", poststart, postend, instart, inend, idx);
    root->left = build(poststart, poststart + idx - instart, instart, idx);
    root->right = build(poststart + idx - instart, postend - 1, idx + 1, inend);
    return root;
}

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &postorder[i]);
    }
    for (int i = 0; i < N; i++) {
        scanf("%d", &inorder[i]);
    }

    node *root = build(0, N, 0, N);

    queue<node *> q;
    printf("%d", root->val);
    q.push(root->left);
    q.push(root->right);
    while (!q.empty()) {
        node *p = q.front();
        q.pop();
        if (p == 0) continue;
        q.push(p->left);
        q.push(p->right);
        printf(" %d", p->val);
    }
    printf("\n");

    

    return 0;
}