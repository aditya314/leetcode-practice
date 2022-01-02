const int N = 5e6 + 7;
class Solution {
private: 
    int dfs(vector<vector<int>> &nums, int idx, int last, vector<int> &memo){
        if(idx >= nums.size())
            return 0;
        if(memo[idx] != -1)    // here, our memo store maximum profit we can make on where we left/over the last job (i.e. lastJob time)
            return memo[idx];
        int lo = idx + 1, hi = nums.size() - 1, nextJobTime = nums.size() + 1;
        while(lo <= hi){
            int mid = (lo + hi) >> 1;
            if(nums[mid][0] >= nums[idx][1]){
                nextJobTime = mid;
                hi = mid - 1;
            }else
                lo = mid + 1;
        }
        int sub_res = dfs(nums, idx + 1, last, memo);
        return memo[idx] = max(sub_res, nums[idx][2] + dfs(nums, nextJobTime, nums[idx][1], memo));
    }
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();   
        vector<vector<int>> nums;
        for(int i = 0; i < n; ++i)  
            nums.push_back({startTime[i], endTime[i], profit[i]});

        vector<int> memo(N + 1, -1);            
        sort(nums.begin(), nums.end());
        return dfs(nums, 0, 1, memo);
    }
};