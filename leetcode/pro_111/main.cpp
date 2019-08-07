#include<bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:

    void dfs(TreeNode* node, int* deepth, int curDeepth) {
        
        // cout<<"curDeep:"<<curDeepth<<endl;
        if (node == NULL) {
            return ;
        }

        if (node != NULL && node -> left == NULL && node -> right == NULL) {
            *deepth = min(*deepth,  curDeepth);
            cout<<*deepth;
            return ;
        }

        dfs(node -> left, deepth, curDeepth + 1);
        dfs(node -> right, deepth, curDeepth + 1);
        }

    int minDepth(TreeNode* root) {
        
        int deepth = 100000;
        dfs(root, &deepth, 1);
        return deepth;
    }
    
    
};

int main() {

    TreeNode root = TreeNode(3);
    root.left = new TreeNode(9);
    root.right = new TreeNode(20);
    root.left ->left = new TreeNode(15);
    root.left -> right = new TreeNode(7);

    Solution solution = Solution();
    int res = solution.minDepth(&root);
    cout<<res<<endl;
    return 0;
}
