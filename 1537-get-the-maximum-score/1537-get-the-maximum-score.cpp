class Solution {
private:
    const long long MOD = 1e9 + 7;
    
public:
    int maxSum(vector<int>& nums1, vector<int>& nums2) {
        int i = 0, j = 0, n = nums1.size(), m = nums2.size();
        long long sum1 = 0, sum2 = 0, max_sum = 0;
        while(i < n && j < m){
            if(nums1[i] < nums2[j]){
                sum1 += nums1[i];
                i++;
            }
            else if(nums1[i] > nums2[j]){
                //don't mod this
                // The comparison between two numbers after mod may makes the bigger number seem smaller.
                // I supposed that's why we mod the answer at the very end rather than in the while loop in this case
                sum2 += nums2[j];
                j++;
            }
            else{
                max_sum = (max_sum +  (max(sum1, sum2) + nums1[i])) % MOD;
                sum1 = sum2 = 0;
                i++;    j++;
            }
        }
        while(i < n){
            sum1 += nums1[i];
            i++;
        }
        while(j < m){
            sum2 += nums2[j];
            j++;
        }
        max_sum = (max_sum + max(sum1, sum2));
        return ((int)(max_sum % MOD));
    }
};