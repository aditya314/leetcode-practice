class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate, curr_vote_count = 0;
        for(int i = 0; i < nums.size(); i++){
            if(curr_vote_count == 0)    candidate = nums[i];
            curr_vote_count += (nums[i] == candidate) ? 1 : -1;
        }
        return candidate;
    }
};