class Solution {
private:
    class TreeNode {
    public:
        TreeNode* children[2];
    };
    TreeNode* root;
    void add_to_trie(int num) {
        TreeNode* cur = root;
        for (int i = 31; i >= 0; i--) {
            int bit = ((num >> i) & 1);
            if (cur -> children[bit] == NULL)
                cur -> children[bit] = new TreeNode();
            cur = cur -> children[bit];
        }
    }
    
    int get_max_xor_from_trie(int num) {
        TreeNode* cur = root;
        int res = 0;
        for (int i = 31; i >= 0; i--) {
            int bit = ((num >> i) & 1);
            int expected_bit = bit ^ 1;
            if (cur -> children[expected_bit]) {
                res += 1 << i;
                cur = cur -> children[expected_bit];
            }
            else 
                cur = cur -> children[bit];
        }
        return res;
    }
public:
    int findMaximumXOR(vector<int>& nums) {
        root = new TreeNode();
        for(int num :  nums)    add_to_trie(num);
        
        int res = 0;
        for (int num : nums) 
            res = max(res, get_max_xor_from_trie(num));
        return res;
    }
};