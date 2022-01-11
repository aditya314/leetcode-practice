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
    int sum;
    bool is_leaf(TreeNode* root){
        return (!(root->right) && !(root->left));
    }
    int binary_str_to_decimal_num(string s){
        int i, n = s.length(), res = 0;
        for(i = 0; i < n; i++){
            if(s[i] == '1')     res += pow(2, n - 1 - i);
        }
        return res;
    }
    void accumlate_sum_to_leaf(TreeNode* root, string bin_str, int& sum){
        if(!root)   return;
        bin_str = bin_str + (char)(root->val + '0');
        if(is_leaf(root)){
            sum += binary_str_to_decimal_num(bin_str);
        }
        else{
            accumlate_sum_to_leaf(root->left, bin_str, sum);
            accumlate_sum_to_leaf(root->right, bin_str, sum);
        }
    }
public:
    int sumRootToLeaf(TreeNode* root) {
        sum = 0;
        accumlate_sum_to_leaf(root, "", sum);
        return sum;
    }
};