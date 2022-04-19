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
    TreeNode *first_misplace = nullptr, *second_misplace = nullptr, *prev = nullptr;
    void find_misplaced_nodes_by_inorder_traverse(TreeNode* root){
        if(!root)   return;
        find_misplaced_nodes_by_inorder_traverse(root -> left);
        if(prev && prev -> val >= root -> val){
            if(!first_misplace)
                first_misplace = prev;
            second_misplace = root;
        }
        prev = root;
        find_misplaced_nodes_by_inorder_traverse(root -> right);
    }
public:
    void recoverTree(TreeNode* root) {
        find_misplaced_nodes_by_inorder_traverse(root);
        swap(first_misplace -> val, second_misplace -> val);
    }
};