class Solution {
    public int missingNumber(int[] nums) {
        int missingNum = 0, i = 0;
	    for (i = 1; i <= nums.length; i++)
		    missingNum = missingNum ^ i ^ nums[i - 1];
	    return missingNum;
    }
}