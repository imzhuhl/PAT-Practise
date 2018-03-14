#include <iostream>
using namespace std;

int k, n;

bool judge1 = true;
bool judge2 = true;

struct Node {
    int val;
    int color;  // 0 black, 1 red
    Node *left, *right;
} node[31];
int cnt = -1;

void insert(Node *cn) {
    Node *root = &node[0];
    Node *pa = root;
    if (cn == root) 
        return;
    while (root != 0) {
        pa = root;
        if (cn->val < root->val) {
            root = root->left;
        } else {
            root = root->right;
        }
    }
    if (cn->val < pa->val) {
        pa->left = cn;
    } else {
        pa->right = cn;
    }
}


void check1(Node *p) {
    if (p == 0 || judge1 == false) 
        return;
    if (p->color == 1) {
        if (p->left != 0 && p->left->color == 1) {
            judge1 = false;
            return;
        }
        if (p->right != 0 && p->right->color == 1) {
            judge1 = false;
            return;
        }    
    }
    check1(p->left);
    check1(p->right);
}

void check2(Node *p, int num) {
    if (judge2 == false) {
        return;
    }
    if (p == 0) {
        if (cnt == -1) {
            cnt = num;
        } else if (cnt != num) {
            judge2 = false;
        }
        return;
    }

    if (p->color == 0) num++;

    check2(p->left, num);
    check2(p->right, num);

}

int main() {
    scanf("%d", &k);
    for (int w = 0; w < k; w++) {
        for (int i = 0; i < 31; i++) {
            node[i].val = node[i].color = 0;
            node[i].left = node[i].right = 0;
        }
        bool judge = true;
        judge1 = true;
        judge2 = true;

        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            int x;
            scanf("%d", &x);
            Node *cn = &node[i];
            if (x < 0) {
                cn->color = 1;
                cn->val = -x;
            } else {
                cn->color = 0;
                cn->val = x;
            }
            cn->left = cn->right = 0;
            insert(cn);
        }
        Node *root = &node[0];
        if (root->color == 1) {
            judge = false;
        }
        check1(&node[0]);
        judge = judge1;

        for (int i = 0; i < n; i++) {
            cnt = -1;
            check2(&node[i], 0);
            if (judge2 == false) {
                judge = false;
                break;
            }
        }

        if (judge)
            printf("Yes\n");
        else
            printf("No\n");

    }


    return 0;
}