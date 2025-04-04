class Solution {
    public:
        TreeNode* lcaDeepestLeaves(TreeNode* root) { 
            return dfs(root).second; 
        }
        pair<int, TreeNode*> dfs(TreeNode* root) {
            if (!root)
                return {0, nullptr};
    
            auto left = dfs(root->left);
            auto right = dfs(root->right);
    
            if (left.first == right.first) {
                return {left.first + 1, root}; 
            } else if (left.first > right.first) {
                return {left.first + 1, left.second};
            } else {
                return {right.first + 1, right.second};
            }
        }
    };