class Solution {
    public int countVowelStrings(int n) {
        this.dp = new Integer[n + 1][vowel_count];
        return getSortedVowelStringsCount(n, 0); 
    }
    public int getSortedVowelStringsCount(int n, int vowel_index){
        if(n == 0)  
            return 1;
        if(vowel_index == vowel_count)  
            return 0;
        if(dp[n][vowel_index] == null){
            int count = 0;
            //include this vowel and continue
            count += getSortedVowelStringsCount(n - 1, vowel_index);
            //skip this vowel and move with greater vowel
            count += getSortedVowelStringsCount(n, vowel_index + 1);
            
            dp[n][vowel_index] = count;
        }
        return dp[n][vowel_index];
    }
    private static final int vowel_count = 5;
    private Integer[][] dp;
    //private char[] vowels = {'a', 'e', 'i', 'o', 'u'};
}