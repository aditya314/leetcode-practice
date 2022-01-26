class Solution {
private:
    int get_two_sum_smallest_diff(vector<int>& nums, int target, int i){
        int low = i + 1, high = nums.size() - 1, smallest_diff = INT_MAX;
        while(low < high){
            int sum = nums[low] + nums[high];
            if(abs(target - sum) < abs(smallest_diff))  smallest_diff = target - sum;
            if(sum < target)    low++;
            else    high--;
        }
        return smallest_diff;
    }
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int smallest_diff = INT_MAX;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i++){
            int smallest_diff_for_index = get_two_sum_smallest_diff(nums, target - nums[i], i);
            if(abs(smallest_diff_for_index) < abs(smallest_diff))   smallest_diff = smallest_diff_for_index;
        }
        int triplet_sum = target - smallest_diff;
        return triplet_sum;
    }
};