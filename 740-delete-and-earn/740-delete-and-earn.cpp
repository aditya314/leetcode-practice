class Solution {
    //house robber variation
    //maxPoints(num) to return the maximum points that we can gain if we only consider all the elements in nums with values between 0 and num.
    //for an arbitrary x, maxPoints(x) = max(maxPoints(x - 1), maxPoints(x - 2) + gain),
    //where gain is the number of points we can gain from taking x.
public:
    int deleteAndEarn(vector<int>& nums) {
        int n = 10001;
        //If you take a number, you might as well take them all.
        vector<int> values(n, 0);
        for (int num : nums)
            values[num] += num;

        int max_sum_including_current = 0, max_sum_excluding_current = 0, max_sum = 0;
        for(int i = 0; i < n; i++){
            max_sum = max(max_sum_including_current, max_sum_excluding_current +  values[i]);
            max_sum_excluding_current = max_sum_including_current;
            max_sum_including_current = max_sum;
        }
        return max_sum;
    }
};