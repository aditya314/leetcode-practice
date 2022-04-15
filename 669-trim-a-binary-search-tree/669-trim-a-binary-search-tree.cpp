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
public:
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if(!root)   return root;
        TreeNode* left_trim_bst = trimBST(root -> left, low, high);
        TreeNode* right_trim_bst = trimBST(root -> right, low, high);
        if(root -> val < low)
            return right_trim_bst;
        if(root -> val > high)
            return left_trim_bst;
        root -> left = left_trim_bst;
        root -> right = right_trim_bst;
        return root;
    }
};