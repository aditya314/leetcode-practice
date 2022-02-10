class Solution {
private:
    //TLE solution O(n*m*m)??
    int n, m;
    unordered_map<int, long long> dp;
    int get_hash_code(int i, int j){
        return (i * m + j);
    }
    long long get_max_point(vector<vector<int>>& points, int i, int prev_col){
        if(i >= n)  return 0;
        int hash_code = get_hash_code(i, prev_col);
        if(dp.find(hash_code) != dp.end())
                return dp[hash_code];
        long max_points = INT_MIN;
        for(int j = 0; j < m; j++){
            long long step_point = points[i][j] - 
                                        ((prev_col != -1) ? abs(prev_col - j) : 0);
            long long total_point = step_point + get_max_point(points, i + 1, j);
            if(total_point > max_points)    max_points = total_point;
        }
        dp[hash_code] = max_points;
        return max_points;
    }
public:
    // long long maxPoints(vector<vector<int>>& points) {
    //     n = points.size();
    //     m = points[0].size();
    //     return get_max_point(points, 0, -1);
    // }
    long long maxPoints(vector<vector<int>>& P) {
        long long m = P.size(), n = P[0].size();
        vector<long long> pre(n);
        for (int i = 0; i < n; ++i) pre[i] = P[0][i];
        for (int i = 0; i < m - 1; ++i){
            vector<long long> lft(n, 0), rgt(n, 0), cur(n, 0);
            lft[0] = pre[0];
            rgt[n - 1] = pre[n - 1];
            for (int j = 1; j < n; ++j){
                lft[j] = max(lft[j - 1] - 1, pre[j]);
            }
            for (int j = n - 2; j >= 0; --j){
                rgt[j] = max(rgt[j + 1] - 1, pre[j]);
            }
            for (int j = 0; j < n; ++j){
                cur[j] = P[i + 1][j] + max(lft[j], rgt[j]);
            }
            pre = cur;
        }
        long long ans = 0;
        for (int i = 0; i < n; ++i)
            ans = max(ans, pre[i]);
        return ans;
    }

    
    
};