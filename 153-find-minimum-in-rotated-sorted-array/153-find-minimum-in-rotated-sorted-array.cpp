class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int low = 0, high = n - 1, answer = nums[0];
        while(low <= high){
            int mid = low + ((high - low) >> 1);
            if(nums[0] <= nums[mid]){
                low = mid + 1;
            }
            else{
                answer = min(answer, nums[mid]);
                high = mid - 1;
            }
        }
        return answer;
    }
};