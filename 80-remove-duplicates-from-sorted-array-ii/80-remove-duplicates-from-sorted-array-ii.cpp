class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0, j = 0, n = nums.size();
        for(int i = 0; i < n; i++){
            if(j > 1 && nums[j - 2] == nums[j - 1] && nums[j - 1] == nums[i])   continue;
            nums[j++] = nums[i];
        }
        return j;
    }
};