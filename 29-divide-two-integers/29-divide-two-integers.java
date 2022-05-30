class Solution {
    public int divide(int dividend, int divisor) {
        if(Integer.MIN_VALUE == dividend && divisor == -1)
            return Integer.MAX_VALUE;
        int quotient = 0;
        int a = Math.abs(dividend);
        int b = Math.abs(divisor);
        while((a - b) >= 0){
            int maxSubtract = b;
            int subtractCount = 1;
            while((a - (maxSubtract << 1)) >= 0){
                maxSubtract <<= 1;
                subtractCount <<= 1;
            }
            a -= maxSubtract;
            quotient += subtractCount;
        }
        return ((dividend > 0) == (divisor > 0)) ? quotient : -quotient;
    }
}