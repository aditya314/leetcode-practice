class Solution {
public:
    //https://leetcode.com/problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit/discuss/609743/Java-Detailed-Explanation-Sliding-Window-Deque-O(N)
    int longestSubarray(vector<int>& nums, int limit) {
        deque<int> min_window, max_window;
        int start = 0, ans = 1;
        for(int end = 0; end < nums.size(); end++){
            while(!max_window.empty() && max_window.back() < nums[end])
                max_window.pop_back();
            max_window.push_back(nums[end]);
            
            while(!min_window.empty() && min_window.back() > nums[end])
                min_window.pop_back();
            min_window.push_back(nums[end]);

            while(max_window.front() - min_window.front() > limit){
                if(nums[start] == min_window.front())
                    min_window.pop_front();
                if(nums[start] == max_window.front())
                    max_window.pop_front();
                start++;
            }
            
            ans = max(ans, end - start + 1);
        }
        return ans;
    }
};