class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = -1, curr_vote_count = 0;
        for(int i = 0; i < nums.size(); i++){
            if(candidate == nums[i])   curr_vote_count++;
            else if(curr_vote_count == 0)    candidate = nums[i];
            else    curr_vote_count--;
        }
        return candidate;
    }
};