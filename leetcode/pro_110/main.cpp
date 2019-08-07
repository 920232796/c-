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

    int solve(TreeNode* node) {
        
        if (node == NULL) {
            return 0;
        }
        int leftDeep = solve(node -> left);
        int rightDeep = solve(node -> right);
      
        if (leftDeep >= 0 && rightDeep >= 0 && abs(leftDeep - rightDeep) <= 1) {
            return 1 + max(leftDeep, rightDeep);
        }
        
        
        return -1;

    }

    bool isBalanced(TreeNode* root) {
        
        if (solve(root) == -1) {
            return false;
        }

        return true;

    }
};

int main() {

    cout<<"hello world"<<endl;
    TreeNode* root = new TreeNode(3);
    root -> left = new TreeNode(9);
    root -> right = new TreeNode(20);
    root -> right -> left = new TreeNode(15);
    root -> right -> right = new TreeNode(7);

    Solution solution = Solution();

    bool res = solution.isBalanced(root);

    cout<<res<<endl;

}