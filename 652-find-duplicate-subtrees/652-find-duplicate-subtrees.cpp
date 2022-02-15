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
    unordered_map<string, int> subtree_freq;
    vector<TreeNode*> duplicate_nodes;
    string serialise_tree(TreeNode* root){
        if(!root)   return "# ";
        string serialised_tree = to_string(root->val) + " " + serialise_tree(root->left) + serialise_tree(root->right);
        subtree_freq[serialised_tree]++;
        if(subtree_freq[serialised_tree] == 2)
             duplicate_nodes.push_back(root);
        return serialised_tree;
    }
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        subtree_freq.clear();
        duplicate_nodes.clear();
        serialise_tree(root);
        return duplicate_nodes;
    }
};