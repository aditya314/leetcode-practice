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
class BSTIterator {
private:
    stack<TreeNode*> st;
    void push_left_nodes(TreeNode* root){
        while(root){
            st.push(root);
            root = root -> left;
        }
    }
public:
    BSTIterator(TreeNode* root) {
        push_left_nodes(root); 
    }
    
    int next() {
        TreeNode* curr_node = st.top();
        st.pop();
        if(curr_node -> right)
            push_left_nodes(curr_node -> right);    
        return curr_node -> val;
    }
    
    bool hasNext() {
        return st.size() > 0;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */