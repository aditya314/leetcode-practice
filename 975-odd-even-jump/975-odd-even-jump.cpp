class Solution {
public:
    int oddEvenJumps(vector<int>& v) {
        /*
            canReach(i) -> bool if can reach starting from given index
        */
        int n = v.size();
        int totalGoodStartingPoints = 1;
        map<int, int> invertedIndex;
        invertedIndex[v[n - 1]] = n - 1;
        
        // Base case 
        vector<bool> canOddJumpReach(n, false);
        canOddJumpReach[n - 1] = true;
        
        vector<bool> canEvenJumpReach(n, false);
        canEvenJumpReach[n - 1] = true;
        
        for(int i = n - 2;i >= 0;i--){
            auto jumpForOdd = invertedIndex.lower_bound(v[i]);// To smallest element greater than v[i]
            auto jumpForEven = invertedIndex.upper_bound(v[i]); // To largest element less than v[i]
            
            if(jumpForOdd != invertedIndex.end()){
                canOddJumpReach[i] = canEvenJumpReach[jumpForOdd->second];
            }
            
            if(jumpForEven != invertedIndex.begin()){
                jumpForEven--;
                canEvenJumpReach[i] = canOddJumpReach[jumpForEven->second];
            }
            
            // First jump is always odd
            if(canOddJumpReach[i])
                totalGoodStartingPoints += 1;
            
            invertedIndex[v[i]] = i;
        }
        return totalGoodStartingPoints;
    }
};