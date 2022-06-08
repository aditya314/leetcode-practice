class Solution {
    public int removePalindromeSub(String s) {
        if(s.isEmpty())     return 0;
        
        int n = s.length();
        for(int i = 0; i < n / 2; i++)
            //We can delete all characters 'a' in the 1st operation,
            //and then all characters 'b' in the 2nd operation.
            if(s.charAt(i) != s.charAt(n - i - 1))
                return 2;

        return 1;
    }
}