class Solution {
    //boils down to Find the Longest Subarray with Sum Equals to TotalSum - X
    public int minOperations(int[] nums, int x) {
        int requiredSum = 0;
        for(int num : nums)
            requiredSum += num;
        requiredSum -= x;
        
        if(requiredSum == 0)    return nums.length;
        
        Map<Integer, Integer> sumHashMap = new HashMap<>();
        sumHashMap.put(0, -1);
        int currSum = 0, answer = Integer.MIN_VALUE;
        for(int i = 0; i < nums.length; i++){
            currSum += nums[i];
            if(sumHashMap.containsKey(currSum - requiredSum))
                answer = Math.max(answer, i - sumHashMap.get(currSum - requiredSum));
            sumHashMap.put(currSum, i);
        }
        
        int minOperations = (answer != Integer.MIN_VALUE) ? (nums.length - answer) : -1;
        return minOperations;
    }
}