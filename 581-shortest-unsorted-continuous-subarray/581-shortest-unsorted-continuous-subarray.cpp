class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        
        //go till first unsorted
        int i = 1;
        while(i < n && nums[i - 1] <= nums[i])   i++;
        int min_element_in_unsorted = INT_MAX;
        while(i < n){
            min_element_in_unsorted = min(min_element_in_unsorted, nums[i]);
            i++;
        }
        
        //go till last unsorted
        int j = n - 2;
        while(j >= 0 && nums[j] <= nums[j + 1])      j--;
        int max_element_in_unsorted = INT_MIN;
        while(j >= 0){
            max_element_in_unsorted = max(max_element_in_unsorted, nums[j]);
            j--;
        }
        
        //find the first element larger than min
        i = 0;
        while(i < n && nums[i] <= min_element_in_unsorted)   i++;
        //find the last element smaller than max
        j = n - 1;
        while(j >= 0 && nums[j] >= max_element_in_unsorted)  j--;
        return (j >= i) ? (j - i + 1) : 0; 
    }
};