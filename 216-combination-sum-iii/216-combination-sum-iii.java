class Solution {
    public List<List<Integer>> combinationSum3(int k, int n) {
        List<List<Integer>> combos = new ArrayList<>();
        getCombinationalSum(combos, new ArrayList<Integer>(), k, 1, n);
        return combos;
    }
    private void getCombinationalSum(List<List<Integer>> combos,
                                            List<Integer> combo, int k, int start, int remainingSum){
        if(combo.size() == k && remainingSum == 0){
            List<Integer> combination = new ArrayList<>(combo);
            combos.add(combination);
            return;
        }
        for(int num = start; num <= 9; num++){
            combo.add(num);
            getCombinationalSum(combos, combo, k, num + 1, remainingSum - num);
            combo.remove(combo.size() - 1);
        }
    }
}