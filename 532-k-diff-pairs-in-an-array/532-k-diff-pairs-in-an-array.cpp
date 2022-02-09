class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int, int> seen_nums;
        for(int num: nums)  seen_nums[num]++;
        int pair_count = 0;
        for(pair<int,int> num_freq : seen_nums){
            int num = num_freq.first;
            int freq = num_freq.second;
            if(k != 0 && seen_nums.find(num + k) != seen_nums.end())
                pair_count++;
            else if(k == 0 && freq > 1)
                pair_count++;
        }
        return pair_count;
    }
};