class Solution {
private:
    bool row_num[9][10], col_num[9][10], cube_num[3][3][10];
    void init_hash(vector<vector<char>>& board){
        memset(row_num, false, sizeof(row_num));
        memset(col_num, false, sizeof(col_num));
        memset(cube_num, false, sizeof(cube_num));
    }
    void add_to_hash(int i, int j, int num){
        row_num[i][num] = true;
        col_num[j][num] = true;
        cube_num[i / 3][j / 3][num] = true;
    }
    bool is_sudoku_state_valid(int i, int j, int num){
        return !(row_num[i][num] || col_num[j][num] || cube_num[i / 3][j / 3][num]);
    }
    
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        init_hash(board);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(board[i][j] != '.'){
                    if(!is_sudoku_state_valid(i, j, (board[i][j] - '0')))   return false;
                    add_to_hash(i, j, (board[i][j] - '0'));
                }
            }
        }
        return true;
    }
};