class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> shifted_grid(n, vector<int>(m, 0));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                int compressed_point = i * m + j;
                int shifted_compressed_point = (compressed_point + k) % (n * m);
                int new_i = shifted_compressed_point / m, new_j = shifted_compressed_point % m;
                shifted_grid[new_i][new_j] = grid[i][j];
            }
        }
        return shifted_grid;
    }
};