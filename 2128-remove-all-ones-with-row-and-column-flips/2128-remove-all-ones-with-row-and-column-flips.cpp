class Solution {
    // Let's say there are some number of 1s in the first row. To get to all 0s matrix it is obvious that we must flip those 1s. If we flip the first row itself then any 0 will turn into 1. So instead we flip all the columns that have 1 in the first row. Now if we think a little deeply, we can realize that we can never flip columns again, because if we do, then 0s in first row will turn to 1s again. So our only option is to flip rows now (starting from second row since first row is already all 0s). Now to get all 0s in the final matrix each row ought to have either only 0s or only 1s. If it has only 0s we don't flip it, if it has only 1s then we flip it. If in any row all the elements are not same, it means it is not possible to get all 0s matrix.
public:
    bool removeOnes(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        for(int j = 0; j < m; j++){
            if(grid[0][j] == 1){
                for(int i = 0; i < n; i++)
                    grid[i][j] ^= 1;
            }
        }
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m - 1; j++){
                if(grid[i][j] != grid[i][j + 1])
                    return false;
            }
        }
        return true;
    }
};