class Solution {
private:
    const int MOD = 1e9 + 7;
public:
    int countOrders(int n) {
        long long ans = 1;
        for(int i = 1; i <= n ;i++){
            // Ways to arrange all pickups, 1*2*3*4*5*...*n
            ans = ans * i;
            // Ways to arrange all deliveries, 1*3*5*...*(2n-1)
            ans = ans * (2 * i - 1);
            ans = ans % MOD;
        }
        return (int) ans;
    }
};