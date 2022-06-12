class Solution {
    public int maximumUniqueSubarray(int[] nums) {
        int start = 0, end = 0, currSum = 0, n = nums.length, maxScore = 0;
        Set<Integer> windowNumbers = new HashSet<>();
        while(end < n){
            if(!windowNumbers.contains(nums[end])){
                currSum += nums[end];
                maxScore = Math.max(maxScore, currSum);
                windowNumbers.add(nums[end++]);
            }
            else{
                currSum -= nums[start];
                windowNumbers.remove(nums[start++]);
            }
        }
        return maxScore;
    }
}