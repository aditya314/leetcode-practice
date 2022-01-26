class Solution {
private:
    void get_two_sum(vector<int>& nums, int i, int target_sum, vector<vector<int>>& three_sum_list){
        int low = i + 1, high = nums.size() - 1;
        while(low < high){
            int sum = nums[low] + nums[high];
            if(sum < target_sum)        low++;
            else if(sum > target_sum)   high--;
            else{
                three_sum_list.push_back({nums[i], nums[low], nums[high]});
                low++;  high--;
                //for duplciates
                while(low < high && nums[low] == nums[low - 1])     low++;
            }
        }
    }
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int target_sum = 0;
        sort(nums.begin(), nums.end());
        vector<vector<int>> three_sum_list;
        for(int i = 0; i < nums.size(); i++){
            //since all number after this will also be >. target_sum, thus never giving a valid answer 
            if(nums[i] > target_sum)    break;
            if(i == 0 || nums[i - 1] != nums[i])     get_two_sum(nums, i, target_sum - nums[i], three_sum_list);
        }
        return three_sum_list;
    }
};