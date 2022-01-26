class Solution {
private:
    int get_two_sum_smaller_count(vector<int>& nums, int target, int i){
        int low = i + 1, high = nums.size() - 1, count = 0;
        while(low < high){
            if(nums[low] + nums[high] < target){
                count += (high - low);
                low++;
            }
            else    high--;
        }
        return count;
    }
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        int count = 0;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i++)
            count += get_two_sum_smaller_count(nums, target - nums[i], i);
        return count;
    }
};