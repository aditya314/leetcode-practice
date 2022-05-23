class Solution {
    public int findMaxForm(String[] strs, int m, int n) {
        if(strs.length == 0 || strs == null)
            return 0;
        dp = new HashMap();
        return maxForm(strs, m, n, 0);
    }
    
    private Map<String,Integer> dp;
    private int maxForm(String[] strs, int m ,int n,int index){
	    if((m == 0 && n == 0) || (index >= strs.length))        return 0;
        
        String key = m + "->" + n + "->" + index;
        if(dp.containsKey(key))    return dp.get(key);
		
        int totalCount = 0;
		//For the current index count the required number of zeros and ones .
        String curr = strs[index];
        int ones = 0, zeros = 0;
        for(char c : curr.toCharArray()){
            if(c == '0')    zeros++;
            else            ones++;
         }
        
        int takenStringCount = 0;
		// if we have the  required number of zeros and ones  we take the current string and update the 
		// remaining zeros and ones and go to the next index;
        if(ones <= n && zeros <= m)
                takenStringCount = 1 + maxForm(strs, m - zeros, n-ones, index + 1);
		// For every position we also the option to skip the current string ;
        int skippedStringNumber = maxForm(strs, m, n, index + 1);
        totalCount = Math.max(skippedStringNumber,takenStringCount);
        dp.put(key, totalCount);
        return totalCount;
    }
}