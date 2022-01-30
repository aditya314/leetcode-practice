class Solution {
public:
    void reverseSubArray(vector<int>& nums, int start, int end){
        while(start <= end){
            swap(nums[start++], nums[end--]);
        }
    }
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        reverseSubArray(nums, 0, n - 1);
        reverseSubArray(nums, 0, k - 1);
        reverseSubArray(nums, k, n - 1);
    }
};