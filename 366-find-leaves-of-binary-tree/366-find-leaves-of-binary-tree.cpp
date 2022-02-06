/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    int get_height(TreeNode* root, vector<vector<int>>& leaves){
        if(!root)   return -1;
        int left_height = get_height(root->left, leaves);
        int right_height = get_height(root->right, leaves);
        int root_height = 1 + max(left_height, right_height);
        if(root_height >= leaves.size())    leaves.push_back({});    
        leaves[root_height].push_back(root->val);
        return root_height;
    }
public:
    vector<vector<int>> findLeaves(TreeNode* root) {
        vector<vector<int>> leaves;
        //leaves[0] -> leaves with height 0
        get_height(root, leaves);
        return leaves;
    }
};