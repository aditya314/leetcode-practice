class Solution {
public:
    int majorityElement(vector<int>& nums) {
        if(nums.size() == 0)    return 0;
        int curr_vote_count = 1;
        int candidate = nums[0];
        for(int i = 1; i < nums.size(); i++){
            if(curr_vote_count == 0)    candidate = nums[i];
            curr_vote_count += (nums[i] == candidate) ? 1 : -1;
        }
        return candidate;
    }
};