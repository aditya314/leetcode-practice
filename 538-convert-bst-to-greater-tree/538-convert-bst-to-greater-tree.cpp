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
    void update_greater_keys_sum(TreeNode* root, int& curr_sum){
        if(!root)   return;
        update_greater_keys_sum(root -> right, curr_sum);
        curr_sum += root -> val;
        root -> val = curr_sum;
        update_greater_keys_sum(root -> left, curr_sum);
    }
public:
    TreeNode* convertBST(TreeNode* root) {
        int curr_sum = 0;
        update_greater_keys_sum(root, curr_sum);
        return root;
    }
};