class Solution {
private:
    bool row_num[9][10], col_num[9][10], cube_num[3][3][10];
    void init_hash(vector<vector<char>>& board, int n, int m){
        memset(row_num, false, sizeof(row_num));
        memset(col_num, false, sizeof(col_num));
        memset(cube_num, false, sizeof(cube_num));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(board[i][j] != '.'){
                    add_to_hash(i, j, (board[i][j] - '0'));
                }
            }
        }
    }
    void add_to_hash(int i, int j, int num){
        row_num[i][num] = true;
        col_num[j][num] = true;
        cube_num[i / 3][j / 3][num] = true;
    }
    void remove_from_hash(int i, int j, int num){
        row_num[i][num] = false;
        col_num[j][num] = false;
        cube_num[i / 3][j / 3][num] = false;
    }
    bool is_sudoku_state_valid(int i, int j, int num){
        return !(row_num[i][num] || col_num[j][num] || cube_num[i / 3][j / 3][num]);
    }
    bool backtrack_sudoku_solution(vector<vector<char>>& board, int i, int j, int n, int m){
        if(i == n)  return true;
        if(j == m)  return backtrack_sudoku_solution(board, i + 1, 0, n, m);
        if(board[i][j] != '.')  return backtrack_sudoku_solution(board, i, j + 1, n, m);
        for(int digit = 1; digit <= 9; digit++){
            if(is_sudoku_state_valid(i, j, digit)){
                board[i][j] = (char) (digit + '0');
                add_to_hash(i, j, digit);
                if(backtrack_sudoku_solution(board, i, j + 1, n, m))  return true;
                board[i][j] = '.';
                remove_from_hash(i, j, digit);
            }
        }
        return false;
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        init_hash(board, n, m);
        backtrack_sudoku_solution(board, 0, 0, n, m);
    }
};