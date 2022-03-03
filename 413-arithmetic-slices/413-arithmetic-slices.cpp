class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int arithmetic_streak = 0, total_slices = 0;
        for(int i = 2; i < nums.size(); i++){
            if(nums[i] - nums[i - 1] == nums[i - 1] - nums[i - 2])
                arithmetic_streak++;
            else{
                total_slices += (arithmetic_streak + 1) * arithmetic_streak / 2;
                arithmetic_streak = 0;
            }
        }
        total_slices += (arithmetic_streak + 1) * arithmetic_streak / 2;
        return total_slices;
    }
};