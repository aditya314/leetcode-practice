class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int candidate1 = -1, candidate2 = -1, count1 = 0, count2 = 0;
        for(int i = 0; i < n; i++){
            if(candidate1 == nums[i])       count1++;
            else if(candidate2 == nums[i])  count2++;
            else if(count1 == 0){
                candidate1 = nums[i];
                count1 = 1;
            }
            else if(count2 == 0){
                candidate2 = nums[i];
                count2 = 1;
            }
            else{
                count1--;   count2--;
            }
        }
        vector<int> candidates;
        int votes1 = 0, votes2 = 0;
        for(int num : nums){
            if(num == candidate1)   votes1++;
            if(num == candidate2)   votes2++;
        }
        if(votes1 > (n /3)) candidates.push_back(candidate1);
        if(candidate1 != candidate2 && votes2 > (n /3)) candidates.push_back(candidate2);
        return candidates;
    }
};