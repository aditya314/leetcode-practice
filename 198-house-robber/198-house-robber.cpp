class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size(), max_sum_including_current = 0, max_sum_excluding_current = 0, max_sum = 0;
        for(int i = 0; i < n; i++){
            max_sum = max(max_sum_including_current, max_sum_excluding_current +  nums[i]);
            max_sum_excluding_current = max_sum_including_current;
            max_sum_including_current = max_sum;
        }
        return max_sum;
    }
};