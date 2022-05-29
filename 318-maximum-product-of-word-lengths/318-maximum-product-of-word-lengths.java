class Solution {
    public int maxProduct(String[] words) {
        if(words == null || words.length == 0)  return 0;
        
        int n = words.length;
        int[] alphabetBitValue = new int[n];
        for(int i = 0; i < n; i++){
            for(int j = 0; j < words[i].length(); j++)
                alphabetBitValue[i] |= (1 << (words[i].charAt(j) - 'a')); 
        }
        
        int maxProduct = 0;
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                if((alphabetBitValue[i] & alphabetBitValue[j]) == 0)
                    maxProduct = Math.max(maxProduct, words[i].length() * words[j].length());
            }
        }
        return maxProduct;
    }
}