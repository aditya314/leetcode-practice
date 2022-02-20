class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        if(n == 0)  return -1;
        if(n == 1)  return nums[0];
        int low = 0, high = n / 2, answer = n;
        while(low <= high){
            int mid = low + ((high - low) >> 1);
            int even_index = mid << 1;
            if(nums[even_index] != nums[even_index + 1]){
                answer = min(answer, even_index);
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return nums[answer];
    }
};