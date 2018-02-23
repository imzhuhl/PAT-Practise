#include <iostream>

using namespace std;

struct node {
    int val;
    node *left;
    node *right;
};

node all[1005];
int N;

int top;
int rst[1005];

void mirror_preorder(node *root) {
    if(root == 0) {
        return;
    }
    rst[top++] = root->val;
    mirror_preorder(root->right);
    mirror_preorder(root->left);
}
void preorder(node *root) {
    if (root == 0) {
        return;
    }
    rst[top++] = root->val;
    preorder(root->left);
    preorder(root->right);
}

void postorder(node *root) {
    if (root == 0) {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    rst[top++] = root->val;
}
void mirror_postorder(node *root) {
    if (root == 0) {
        return;
    }
    mirror_postorder(root->right);
    mirror_postorder(root->left);
    rst[top++] = root->val;
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;

        if (i == 0) {
            all[0].val = x;
            all[0].left = all[0].right = 0;
            continue;
        }

        node *nwnode = &all[i];
        node *root = &all[0];
        node *p = root;
        while (p != 0) {
            if (x < p->val) {
                root = p;
                p = p->left;
            } else {
                root = p;
                p = p->right;
            }
        }
        nwnode->val = x;
        nwnode->left = nwnode->right = 0;
        if (x < root->val) {
            root->left = nwnode;
        } else {
            root->right = nwnode;
        } 
    }

    bool mark1 = true, mark2 = true;
    top = 0;
    preorder(&all[0]);
    for (int i = 0; i < top; i++) {
        if (rst[i] != all[i].val) {
            mark1 = false;
        }
    }
    top = 0;
    mirror_preorder(&all[0]);
    for (int i = 0; i < top; i++) {
        if (rst[i] != all[i].val) {
            mark2 = false;
        }
    }

    top = 0;
    if (!mark1 && !mark2) {
        printf("NO\n");
        return 0;
    } else if (mark1 && !mark2) {
        printf("YES\n");
        postorder(&all[0]);
    } else {
        printf("YES\n");
        mirror_postorder(&all[0]);
    }

    for (int i = 0; i < top; i++) {
        if (i) printf(" ");
        printf("%d", rst[i]);
    }
    printf("\n");

    return 0;
}