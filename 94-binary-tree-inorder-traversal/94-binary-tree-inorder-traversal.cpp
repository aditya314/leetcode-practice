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
    // vector<int> inorderTraversal(TreeNode* root) {
    //     stack<TreeNode*> st;
    //     TreeNode* curr = root;
    //     vector<int> traversal;
    //     while(curr || !st.empty()){
    //         while(curr){
    //             st.push(curr);
    //             curr = curr -> left;
    //         }
    //         curr = st.top();    st.pop();
    //         traversal.push_back(curr->val);
    //         curr = curr -> right;
    //     }
    //     return traversal;
    // }
public:
    vector<int> inorderTraversal(TreeNode* root) {
        TreeNode* curr = root;
        vector<int> traversal;
        while(curr){
            if(curr -> left == NULL){
                traversal.push_back(curr->val);
                curr = curr -> right;
            }
            else{
                TreeNode* inorder_successor = curr->left;
                while(inorder_successor->right && inorder_successor->right != curr)
                        inorder_successor = inorder_successor -> right;
                if(inorder_successor -> right == NULL){
                    //create thread
                    inorder_successor -> right = curr;
                    curr = curr -> left;
                }
                else if(inorder_successor->right == curr){
                    //remove thread
                    inorder_successor -> right = NULL;
                    traversal.push_back(curr->val);
                    curr = curr -> right;
                }
                else{
                    cout<<"Threading went wrong!!";
                }
            }
        }
        return traversal;
    }
};