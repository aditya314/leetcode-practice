class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        if(n == 0)  return 0;
        // int max_subarray_product = nums[0];
        // int min_subarray_product = nums[0];
        // int answer = nums[0];
        // for(int i = 1;i < n; i++){
        //     if(nums[i] < 0){
        //         swap(max_subarray_product, min_subarray_product);
        //     }
        //     max_subarray_product = max(nums[i], max_subarray_product * nums[i]);
        //     min_subarray_product = min(nums[i], min_subarray_product * nums[i]);
        //     answer = max(answer, max_subarray_product);
        // }
        // return answer;
        int answer = nums[0], prefix_product = 1, suffix_product = 1;
        for (int i = 0; i < n; i++) {
            prefix_product = prefix_product * nums[i];
            suffix_product = suffix_product * nums[n - 1 - i];
            answer = max(answer, max(prefix_product, suffix_product));
            if(prefix_product == 0)  prefix_product = 1;
            if(suffix_product == 0)  suffix_product = 1;
        }
        return answer;
    }
};