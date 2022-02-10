class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> prefix_sum_freq;
        int prefix_sum = 0, ans = 0;
        prefix_sum_freq[prefix_sum]++;
        for(int num : nums){
            prefix_sum += num;
            ans += prefix_sum_freq[prefix_sum - k];
            prefix_sum_freq[prefix_sum]++;          
        }
        return ans;
    }
};