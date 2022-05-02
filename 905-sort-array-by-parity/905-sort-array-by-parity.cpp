class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int write_head = 0, n = nums.size();
        for(int read_head = 0; read_head < n; read_head++){
            if(nums[read_head] % 2 == 0){
                swap(nums[read_head], nums[write_head]);
                write_head++;
            }
        }
        return nums;
    }
};