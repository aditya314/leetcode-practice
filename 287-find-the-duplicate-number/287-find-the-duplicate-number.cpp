class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        if(nums.empty())  return -1;
        int hare = nums[0], tortoise = nums[0];
        do {
            hare = nums[nums[hare]];
            tortoise = nums[tortoise];
        } while(hare != tortoise);
        
        tortoise = nums[0];
        while(hare != tortoise){
            hare = nums[hare];
            tortoise = nums[tortoise];
        }
        return hare;
    }
};