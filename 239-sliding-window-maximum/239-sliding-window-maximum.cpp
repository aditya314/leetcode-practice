class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> sliding_window_max;
        for (int i = 0; i < nums.size(); i++) {
            while(!dq.empty() && dq.front() <= i-k)   dq.pop_front();
            while (!dq.empty() && nums[dq.back()] < nums[i])    dq.pop_back();
            dq.push_back(i);
            if (i >= k - 1) sliding_window_max.push_back(nums[dq.front()]);
        }
        return sliding_window_max;
    }
};