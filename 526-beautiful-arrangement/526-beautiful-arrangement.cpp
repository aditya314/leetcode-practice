class Solution {
private:
    void permute(vector<int> nums, int i, int& count){
        if(i == nums.size())    count++;
        for(int j = i; j < nums.size(); j++){
            swap(nums[i], nums[j]);
            if(nums[i] % (i + 1) == 0 || (i + 1) % nums[i] == 0)
                permute(nums, i + 1, count);
            swap(nums[i], nums[j]);
        }
    }
public:
    int countArrangement(int n) {
        vector<int> nums;
        for(int i = 1; i <= n; i++)     nums.push_back(i);
        int count = 0;
        permute(nums, 0, count);
        return count;
    }
};