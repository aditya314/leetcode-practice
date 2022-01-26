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
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        stack<TreeNode*> s1, s2;
        vector<int> all_elements;
        TreeNode *curr1 = root1, *curr2 = root2;
        while(curr1 || !s1.empty() || curr2 || !s2.empty()){
            while(curr1){
                s1.push(curr1);
                curr1 = curr1 -> left;
            }
            while(curr2){
                s2.push(curr2);
                curr2 = curr2 -> left;
            }
            if(s2.empty() || (!s1.empty() && s1.top() -> val <= s2.top() -> val)){
                curr1 = s1.top();   s1.pop();
                all_elements.push_back(curr1 -> val);
                curr1 = curr1->right;
            }
            else{
                curr2 = s2.top();   s2.pop();
                all_elements.push_back(curr2 -> val);
                curr2 = curr2 -> right;
            }
        }
        return all_elements;
    }
};