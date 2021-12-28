class Solution {
public:
    int jump(vector<int>& nums) {
        int jumps = 0, n = nums.size();
        for(int i = 0, end = 0, max_reach = 0; end < n - 1; end = max_reach){
            jumps++;
            while(i < n && i <= end){
                max_reach = max(max_reach, i + nums[i]);
                i++;
            }
            if(end == max_reach)    return -1;
        }
        return jumps;
    }
};