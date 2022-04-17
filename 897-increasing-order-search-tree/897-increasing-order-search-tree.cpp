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
    void relink_bst(TreeNode* root, TreeNode*& curr){
        if(!root)   return;
        relink_bst(root -> left, curr);
        root -> left = nullptr;
        curr -> right = root;
        curr = root;
        relink_bst(root -> right, curr);
    }
public:
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode* dummy = new TreeNode(0);
        TreeNode* new_bst = dummy;
        relink_bst(root, new_bst);
        return dummy -> right;
    }
};