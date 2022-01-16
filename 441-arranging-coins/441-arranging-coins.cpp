class Solution {
public:
    int arrangeCoins(int n) {
        long lo = 0, hi = n;
        long mid, curr;
        long ans = 0;
        while(lo <= hi) {
            long mid = lo + (hi - lo) / 2;
            curr = mid * (mid + 1) / 2;
            if(curr <= n){
                ans = max(ans, mid);
                lo = mid + 1;
            }else
                hi = mid - 1;
        }
        return ans;
    }
};