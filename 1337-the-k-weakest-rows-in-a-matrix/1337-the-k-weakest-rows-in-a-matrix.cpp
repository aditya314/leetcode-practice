class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<int> k_weakest(k);
        int n = mat.size(), m = mat[0].size(), idx = 0;
        for(int j = 0; j < m && idx < k; j++){
            for(int i = 0; i < n && idx < k; i++){
                if(mat[i][j] == 0 && (j == 0 || mat[i][j - 1] == 1)){
                    k_weakest[idx] = i;
                    idx++;
                }
            }
        }
        
        // If there aren't enough, it's because some of the first k weakest rows
        // are entirely 1's. We need to include the ones with the lowest indexes
        for(int i = 0; i < n && idx < k; i++){
            if(mat[i][m - 1] == 1){
                k_weakest[idx] = i;
                idx++;
            }
        }
        
        return k_weakest;
    }
};