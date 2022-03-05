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

        int take = 0, skip = 0;
        for (int i = 0; i < n; i++) {
            int takei = skip + values[i];
            int skipi = max(skip, take);
            take = takei;
            skip = skipi;
        }
        return max(take, skip); 
    }
};