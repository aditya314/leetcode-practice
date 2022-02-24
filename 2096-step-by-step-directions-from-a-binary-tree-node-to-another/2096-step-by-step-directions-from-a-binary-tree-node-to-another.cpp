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
    bool get_path_to_node(TreeNode* root, int target_value, string& path){
        if(!root)   return false;
        if(root -> val == target_value)     return true;
        path.push_back('L');
        if(get_path_to_node(root -> left, target_value, path))
            return true;
        path.pop_back();
        path.push_back('R');
        if(get_path_to_node(root -> right, target_value, path))
            return true;
        path.pop_back();
        return false;
    }
    TreeNode* get_lca(TreeNode* root, int a, int b){
        if(!root)   return root;
        if(root -> val == a || root -> val == b)
            return root;
        TreeNode* left_res = get_lca(root -> left, a, b);
        TreeNode* right_res = get_lca(root -> right, a, b);
        return (left_res && right_res) ? root : (left_res ? left_res : right_res);
    }
public:
    string getDirections(TreeNode* root, int startValue, int destValue) {
        TreeNode* lca_node = get_lca(root, startValue, destValue);
        string start_path, dest_path;
        get_path_to_node(lca_node, startValue, start_path);
        get_path_to_node(lca_node, destValue, dest_path);
        for(char &ch : start_path)  ch = 'U';
        return start_path + dest_path;
    }
};