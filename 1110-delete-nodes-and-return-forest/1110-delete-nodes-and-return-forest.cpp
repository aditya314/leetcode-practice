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
    TreeNode* break_tree_to_forest(TreeNode* root, bool is_root, unordered_set<int>& deletion_set, vector<TreeNode*>& forest){
        if(!root)   return root;
        bool to_be_deleted = deletion_set.find(root->val) != deletion_set.end();
        if(is_root && not to_be_deleted)  forest.push_back(root);
        root->left = break_tree_to_forest(root->left, to_be_deleted, deletion_set, forest);
        root->right = break_tree_to_forest(root->right, to_be_deleted, deletion_set, forest);
        return (to_be_deleted) ? NULL : root;
    }
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_set<int> deletion_set(to_delete.begin(), to_delete.end());
        vector<TreeNode*> forest;
        break_tree_to_forest(root, true, deletion_set, forest);
        return forest;
    }
};