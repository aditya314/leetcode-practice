class Solution {
    
    public List<List<String>> solveNQueens(int n) {
        char[][] board = new char[n][n];
        for(char[] row : board){
            Arrays.fill(row, '.');
        }
        List<List<String>> answer = new ArrayList<List<String>>();
        getConfig(board, 0, n, answer);
        return answer;
    }
    
    public boolean isValidConfig(char[][] board, int row, int col, int n){
        for(int i = 0; i < row; i++){
            if(board[i][col] == 'Q')    return false;
        }
        
        int i = row - 1, j = col - 1;
        while(i >= 0 && j >= 0){
            if(board[i][j] == 'Q')  return false;
            i--;    j--;
        }
        
        i = row - 1; j = col + 1;
        while(i >= 0 && j < n){
            if(board[i][j] == 'Q')  return false;
            i--;    j++;
        }
        
        return true;
    }
    
    public void addToAnswer(char[][] board, List<List<String>> answer){
        List<String> rows = new ArrayList<String>();
        for(char[] row : board){
            rows.add(String.valueOf(row));
        }
        answer.add(rows);
    }
    
    public void getConfig(char[][] board, int i, int n, List<List<String>> answer){
        if(i >= n){
            addToAnswer(board, answer);
        }
        else{
            for(int j = 0; j < n; j++){
                if(isValidConfig(board, i, j, n)){
                    board[i][j] = 'Q';
                    getConfig(board, i + 1, n, answer);
                    board[i][j] = '.';
                }
            }
        }
    }
    
}