class Solution {
    //[2nd bit, 1st bit] = [next state, current state]
    //Since every 2nd state is by default dead, no need to consider transition 01 -> 00.
    //Transition 01 -> 11: when board == 1 and lives >= 2 && lives <= 3.
    //Transition 00 -> 10: when board == 0 and lives == 3.
private:
    int get_live_neighbours_count(vector<vector<int>>& board, int i, int j, int n, int m){
        int lives = 0;
        for(int x = max(i - 1, 0); x <= min(i + 1, n - 1); x++) {
            for(int y = max(j - 1, 0); y <= min(j + 1, m - 1); y++) {
                lives += board[x][y] & 1;
            }
        }
        lives -= board[i][j] & 1;
        return lives;
    }
public:
    void gameOfLife(vector<vector<int>>& board) {
        int n = board.size(), m = board[0].size();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                int lives = get_live_neighbours_count(board, i, j, n, m);
                
                if(board[i][j] == 1 && (lives == 2 || lives == 3))
                    board[i][j] = 3;
                else if(board[i][j] == 0 && lives == 3)
                    board[i][j] = 2;
                
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                board[i][j] >>= 1; 
            }
        }
    }
};