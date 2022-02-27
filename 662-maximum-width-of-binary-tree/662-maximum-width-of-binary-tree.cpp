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
    unsigned int max_width;
    unordered_map<int, unsigned int> leftmost_col_index;
    void traverse_to_get_width(TreeNode* root, int level, unsigned int col_index){
        if(leftmost_col_index.find(level) == leftmost_col_index.end())
            leftmost_col_index[level] = col_index;
        this -> max_width = max(this -> max_width, col_index - leftmost_col_index[level] + 1);
        if(root -> left)
            traverse_to_get_width(root -> left, level + 1, col_index * 2 + 1);
        if(root -> right)
            traverse_to_get_width(root -> right, level + 1, col_index * 2 + 2);
    }
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(!root)   return 0;
        traverse_to_get_width(root, 0, 0);
        return (int)max_width;
    }
};


//if we user horizontal depth of hd - 1 and hd + 1
//we get 6 but the answer should be 8
//why? beacuse we would also conside null nodes,  
//             1
//         3        2
//     5    null null   9
// 6    null          null  7

