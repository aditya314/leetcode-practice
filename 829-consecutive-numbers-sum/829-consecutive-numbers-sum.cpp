class Solution {
public:
    int consecutiveNumbersSum(int n) {
        int ans = 0;
        //https://leetcode.com/problems/consecutive-numbers-sum/discuss/1117669/Mathematical-Solution
        for(int k = 1; k * k < 2 * n; k++){
            if((n - k * (k - 1) / 2) % k == 0)      
                ans++;
        }
        return ans;
    }
};