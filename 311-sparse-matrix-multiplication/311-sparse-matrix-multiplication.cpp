class Solution {
    //naive approach
    // for (row = 0 to n) {
    //     for (col = 0 to m) {
    //         for (elementPos = 0 to k) {
    //             ans[row][col] += mat1[row][elementPos] * mat2[elementPos][col];
    //         }
    //     }
    // }

private:
    vector<vector<pair<int, int>>> compress_matrix(vector<vector<int>>& matrix){
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<pair<int, int>>> compressed_matrix(n);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(matrix[i][j] != 0){
                    compressed_matrix[i].push_back({matrix[i][j], j});
                }
            }
        }
        return compressed_matrix;
    }
public:
    vector<vector<int>> multiply(vector<vector<int>>& mat1, vector<vector<int>>& mat2) {
        int m = mat1.size(), k = mat2.size(), n = mat2[0].size();
        //k = mat2.size() = mat1[0].size()
        vector<vector<pair<int, int>>> A = compress_matrix(mat1);
        vector<vector<pair<int, int>>> B = compress_matrix(mat2);
        
        vector<vector<int>> answer(m, vector<int>(n, 0));
        for(int Ai = 0; Ai < m; Ai++){
            // Iterate on all current 'row' non-zero elements of mat1.
            for(auto [A_val, Aj] : A[Ai]){
                // Multiply and add all non-zero elements of mat2
                // where the row is equal to col of current element of mat1.
                for(auto [B_val, Bj] : B[Aj]){
                    answer[Ai][Bj] += (A_val * B_val);
                }
            }
        }
        return answer;
    }
};