class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> spiral_tarversal;
        if(matrix.size() == 0)  return spiral_tarversal;
        int row_start = 0, row_end = matrix.size() - 1, col_start = 0, col_end = matrix[0].size() - 1;
        while(row_start <= row_end && col_start <= col_end){
            for(int j = col_start; j <= col_end; j++)      
                spiral_tarversal.push_back(matrix[row_start][j]);
            row_start++;
            
            for(int i = row_start; i <= row_end; i++)
                spiral_tarversal.push_back(matrix[i][col_end]);
            col_end--;
            
            if(row_start <= row_end){
                for(int j = col_end; j >= col_start; j--)
                    spiral_tarversal.push_back(matrix[row_end][j]);
                row_end--;
            }
            if(col_start <= col_end){
                for(int i = row_end; i >= row_start; i--)
                    spiral_tarversal.push_back(matrix[i][col_start]);
                col_start++;
            }
        }
        return spiral_tarversal;
    }
};