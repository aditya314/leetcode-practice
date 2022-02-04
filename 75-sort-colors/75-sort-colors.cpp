class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = 0, unknown = 0, high = nums.size() -1;
        while(unknown <= high){
            if(nums[unknown] == 0){
                swap(nums[low], nums[unknown]);
                low++;  unknown++;
            }
            else if(nums[unknown] == 1){
                unknown++;
            }
            else if(nums[unknown] == 2){
                swap(nums[unknown], nums[high]);
                high--;
            }
        }
    }
};