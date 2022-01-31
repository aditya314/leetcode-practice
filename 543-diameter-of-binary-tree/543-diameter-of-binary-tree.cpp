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
    int get_height(TreeNode* root, int& diameter){
        if(!root)   return 0;
        int left_height = get_height(root->left, diameter);
        int right_height = get_height(root->right, diameter);
        diameter = max(diameter, left_height + right_height);
        return max(left_height, right_height)  + 1;
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        get_height(root, diameter);
        return diameter;
    }
};