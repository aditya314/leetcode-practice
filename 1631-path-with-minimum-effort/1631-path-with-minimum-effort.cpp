class Solution {
    //Time: O(M * N * log(MAX_HEIGHT))
    //space: O(M * N)
private:
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};
    vector<vector<bool>> vis;
    int n, m;
    bool is_valid_cell(int x, int y){
        return (x >= 0 && x < n && y >= 0 && y < m && !vis[x][y]);
    }
    bool can_dfs_reach_end(int x, int y, vector<vector<int>>& heights, int max_abs_diff){
        if(x == n - 1 && y == m - 1)    return true;
        vis[x][y] = true;
        for(int k = 0; k < 4; k++){
            int i = x + dx[k];
            int j = y + dy[k];
            if(is_valid_cell(i, j) &&
                    abs(heights[i][j] - heights[x][y]) <= max_abs_diff &&
                        can_dfs_reach_end(i, j, heights, max_abs_diff))  return true;
        }
        return false;
    }
    bool can_reach_destination(vector<vector<int>>& heights, int max_abs_diff){
        n = heights.size();
        m = heights[0].size();
        vis.assign(n, vector<bool>(m, false));
        return can_dfs_reach_end(0, 0, heights, max_abs_diff);
    }
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int low = 0, high = 1e6, min_effort = 1e6;
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(can_reach_destination(heights, mid)){
                high = mid - 1;
                min_effort = mid;
            }
            else
                low = mid + 1;
        }
        return min_effort;
    }
};