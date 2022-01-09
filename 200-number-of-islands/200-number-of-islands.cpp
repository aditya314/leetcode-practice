class Solution {
private:
    int di[4] = {0, 1, 0,-1};
    int dj[4] = {1, 0,-1, 0};
    bool is_valid(int x, int y, int n, int m){
        return !(x < 0 || x >= n || y < 0 || y >= m);
    }
    void DFS(vector<vector<char>>& grid, int i, int j, int n, int m, vector< vector<bool> >& vis){
        vis[i][j] = true;
        for(int k = 0 ; k < 4; k++){
            int x = i + di[k];
            int y = j + dj[k];
            if(is_valid(x, y, n, m) && !vis[x][y] && grid[x][y] == '1'){
                DFS(grid, x, y, n, m, vis);
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        if(n == 0)  return 0;
        int m = grid[0].size();
        vector< vector<bool> > vis(n, vector<bool> (m, false));
        int number_of_islands = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(!vis[i][j] && grid[i][j] == '1'){
                    DFS(grid, i, j, n, m, vis);
                    number_of_islands++;
                }
            }
        }
        return number_of_islands;
    }
};