class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n, 0));
        
        int row_start = 0, row_end = n - 1, col_start = 0, col_end = n - 1, num = 0;
        while(row_start <= row_end && col_start <= col_end){
            
            for(int j = col_start; j <= col_end; j++)
                matrix[row_start][j] = ++num;
            
            for(int i = row_start + 1; i <= row_end; i++)
                matrix[i][col_end] = ++num;
            
            for(int j = col_end - 1; j >= col_start; j--)
                matrix[row_end][j] = ++num;
            
            for(int i = row_end - 1; i >= row_start + 1; i--)
                matrix[i][col_start] = ++num;
            
            row_start++;    col_end--; row_end--; col_start++;
        }
        
        return matrix;
    }
};