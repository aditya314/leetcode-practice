class Solution {
    public boolean hasAllCodes(String s, int k) {
        int neededBits = 1 << k;
        boolean[] foundBit = new boolean[neededBits];
        int allOne = neededBits - 1, hashValue = 0;
        
        for(int i = 0; i < s.length(); i++){
            //new_hash = ((old_hash << 1) & all_one) | last_digit_of_new_hash
            hashValue = ((hashValue << 1) & allOne) | (s.charAt(i) - '0');      
            if(i >= k - 1 && !foundBit[hashValue]){
                foundBit[hashValue] = true;
                neededBits--;
                if(neededBits == 0)     return true;
            }
        }
        
        return false;
    }
}