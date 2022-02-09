class Solution {
private:
    pair<int,int> get_max_element_and_total_sum(vector<int>& nums){
        int sum = 0, max_element = INT_MIN;
        for(int num : nums){
            sum += num;
            max_element = max(max_element, num);
        }     
        return {max_element,sum};
    }
    int is_largest_sum_in_m_subarrays(vector<int>& nums, int largest_sum, int m){
        int n = nums.size(), curr_sum = 0, subarray_required = 1;
        for(int i = 0; i < n; i++){
            if(curr_sum + nums[i] > largest_sum){
                subarray_required++;
                curr_sum = nums[i];
            }
            else    curr_sum += nums[i];
        }
        return (subarray_required <= m);
    }
public:
    int splitArray(vector<int>& nums, int m) {
        pair<int, int> res = get_max_element_and_total_sum(nums);
        int low = res.first, high = res.second;
        int min_sum = INT_MAX;
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(is_largest_sum_in_m_subarrays(nums, mid, m)){
                high = mid - 1;
                min_sum = min(min_sum, mid);
            }
            else{
                low = mid + 1;
            }
        }
        return min_sum;
    }
};