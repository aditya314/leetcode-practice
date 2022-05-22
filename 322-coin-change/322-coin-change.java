class Solution {
    public int coinChange(int[] coins, int amount) {
        return coinChangeUtil(coins,amount);
    }
    private Map<Integer,Integer> dp = new HashMap<>();
    private int coinChangeUtil(int[] coins, int amount){
        if(amount < 0)
            return -1;
        if(amount == 0)
            return 0;
        
        Integer coinCount = dp.get(amount);
        if(coinCount != null)
            return coinCount;
        
        int coinChangeCount = -1;
        for(int i = 0; i < coins.length; i++) {
            int remainingCoinCount = coinChangeUtil(coins, amount - coins[i]);
            if(remainingCoinCount >= 0)
                coinChangeCount = coinChangeCount < 0 ? remainingCoinCount + 1 :
                                                            Math.min(remainingCoinCount + 1, coinChangeCount);
        }
        dp.put(amount, coinChangeCount);
        return coinChangeCount;
    }
}