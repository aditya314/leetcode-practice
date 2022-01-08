class Solution {
private:
    int cherry_cache[71][71][71];
    void init_cache(int n, int m){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                for(int k = 0; k < m; k++){
                    cherry_cache[i][j][k] = -1;
                }
            }
        }
    }
    int get_cherries(vector<vector<int>>& grid, int i, int j1, int j2, int n, int m){
        if(j1 < 0 || j1 >= m || j2 < 0 || j2 >= m || grid[i][j1] == -1 || grid[i][j2] == -1)  return INT_MIN;
        if(i == n - 1)    return (j1 != j2) ? grid[i][j1] + grid[i][j2] : grid[i][j1];
        if(cherry_cache[i][j1][j2] != -1)    return cherry_cache[i][j1][j2];
        int cherry = grid[i][j1];
        if(j1 != j2)  cherry += grid[i][j2];
        int max_move = INT_MIN;
        for(int j1_new = j1 - 1; j1_new <= j1 + 1; j1_new++){
            for(int j2_new = j2 - 1; j2_new <= j2 + 1; j2_new++){
                max_move = max(max_move, get_cherries(grid, i + 1, j1_new, j2_new, n, m));
            }
        }
        cherry += max_move;
        cherry_cache[i][j1][j2] = cherry;
        return cherry;
    }
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        if(n == 0)  return 0;
        int m = grid[0].size();
        init_cache(n, m);
        //start with two pointers at (0,0) and (0, m - 1) and go to the last row. keep both non overlapping
        return max(0, get_cherries(grid, 0, 0, m - 1, n, m));
    }
};
