class Solution {
private:
    int cherry_cache[51][51][51];
    void init_cache(int n){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                for(int k = 0; k < n; k++){
                    cherry_cache[i][j][k] = -1;
                }
            }
        }
    }
    int get_cherries(vector<vector<int>>& grid, int i, int j, int x, int n){
        int y = i + j - x; // assuming both have travelled i + j steps
        if(i >= n || j >= n || x >= n || y >= n || grid[i][j] == -1 || grid[x][y] == -1)                    return INT_MIN;
        if(i == n - 1 && j == n - 1)    return grid[i][j];
        if(cherry_cache[i][j][x] != -1)    return cherry_cache[i][j][x];
        int cherry = grid[i][j];
        if(j != y)  cherry += grid[x][y];
        cherry += max(max(get_cherries(grid, i + 1, j, x, n), get_cherries(grid, i, j + 1, x, n)),
                     max(get_cherries(grid, i, j + 1, x + 1, n), get_cherries(grid, i + 1, j, x + 1, n)));
        cherry_cache[i][j][x] = cherry;
        return cherry;
    }
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        init_cache(n);
        //start with two pointers at 0,0 and go to the end. keep both non overlapping
        return max(0, get_cherries(grid, 0, 0, 0, n));
    }
};