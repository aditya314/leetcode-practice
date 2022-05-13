class Solution {
    //The idea is to try to put every number at the beginning of the array,
    //and then do the same thing for the rest of the array.
    //There is no need to sort because we use a HashSet to track 
    // and make sure each number is put at the begining of the array only once.


    public List<List<Integer>> permuteUnique(int[] nums) {
        List<List<Integer>> permutations = new ArrayList<>();
        permute(nums, permutations, 0);
        return permutations;
    }
    
    private void permute(int[] nums, List<List<Integer>> permutations, int startIndex){
        if(startIndex == nums.length){
            permutations.add(toList(nums));
            return;
        }
        Set<Integer> seen = new HashSet<>();
        for(int i = startIndex; i < nums.length; i++){
            if(seen.add(nums[i])){
                swap(nums, i, startIndex);
                permute(nums, permutations, startIndex + 1);
                swap(nums, i, startIndex); //backtrack
            }
        }
    }
    
    private void swap(int[] nums, int i, int j){
        int temp = nums[j];
        nums[j] = nums[i];
        nums[i] = temp;
    }
    
    private List<Integer> toList(int[] nums) {
        List<Integer> list = new LinkedList<>();
        for (int i : nums)
            list.add(i);
        return list;
    }
}