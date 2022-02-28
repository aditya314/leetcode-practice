class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int n = nums.size();
        if(n == 0)  return {};
        vector<string> ranges;
        int range_start = nums[0], range_end = nums[0];
        for(int i = 1; i < n; i++){
            if(nums[i - 1] + 1 != nums[i]){
                ranges.push_back((range_start == range_end) ? to_string(range_start) :
                                    to_string(range_start) + "->" + to_string(range_end));
                range_start = nums[i];
                range_end = nums[i];
            }
            else
                range_end = nums[i];
        }
        ranges.push_back((range_start == range_end) ? to_string(range_start) :
                                    to_string(range_start) + "->" + to_string(range_end));
        return ranges;        
    }
};