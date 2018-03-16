#include <iostream>
#include <vector>
using namespace std;

int preorder[50001];
int inorder[50001];
vector<int> rst;

void dfs(int preleft, int preright, int inleft, int inright) {
    // printf("%d %d %d %d\n", preleft, preright, inleft, inright);
    if (preleft >= preright) {
        rst.push_back(preorder[preleft]);
        return;
    }
    int v = preorder[preleft];
    int inv;
    for (int i = inleft; i <= inright; i++) {
        if (inorder[i] == v) {
            inv = i;
            break;
        }
    }
    if (inv != inleft)
        dfs(preleft + 1, preleft + inv - inleft, inleft, inv - 1);
    if (inv != inright) 
        dfs(preleft + inv - inleft + 1, preright, inv + 1, inright);

}

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &preorder[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &inorder[i]);
    }

    dfs(0, n - 1, 0, n - 1);
    printf("%d\n", rst[0]);

    return 0;
}