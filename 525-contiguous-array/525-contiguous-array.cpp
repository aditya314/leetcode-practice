class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int sum = 0, max_len = 0;
        unordered_map<int, int> sum_index;
        sum_index[0] = -1;
        for(int i = 0; i < nums.size(); i++){
            sum += (nums[i]) ? 1 : (-1);
            if(sum_index.find(sum) != sum_index.end())
                max_len = max(max_len, i - sum_index[sum]);
            else
                sum_index[sum] = i;  
        }
        return max_len;
    }
};