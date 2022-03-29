class Solution {
    // if the board is:
    // 123
    // 145
    // 111
    // and we crush the vertical row of 1s early,
    //we may not see there was also a horizontal row.
    //To remedy this, we should flag candy that should be crushed first. We could use an auxillary toCrush boolean array, or we could mark it directly on the board by making the entry negative (ie. board[i][j] = -Math.abs(board[i][j]))
private:
    int n, m;
    bool mark_candies_to_crush(vector<vector<int>>& board){
        bool found_crush = false;
        //For each line, we could use a sliding window (or itertools.groupby in Python) to find contiguous segments of the same character. If any of these segments have length 3 or more, we should flag them.
        
        //Alternatively, for each line, we could look at each width-3 slice of the line: if they are all the same, then we should flag those 3. This approcah is used here
        for(int i = 0; i < n; i++){
            for(int j = 0; j + 2 < m; j++){
                int val = abs(board[i][j]);
                if(val != 0 &&
                   val == abs(board[i][j + 1]) && val == abs(board[i][j + 2])){
                    board[i][j] = board[i][j + 1] = board[i][j + 2] = -val;
                    found_crush = true;
                }
            }
        }
        
        for(int i = 0; i + 2 < n; i++){
            for(int j = 0; j < m; j++){
                int val = abs(board[i][j]);
                if(val != 0 &&
                   val == abs(board[i + 1][j]) && val == abs(board[i + 2][j])){
                    board[i][j] = board[i + 1][j] = board[i + 2][j] = -val;
                    found_crush = true;
                }
            }
        }
        return found_crush;
    }
    
    void percolate_candies(vector<vector<int>>& board){
       // One way is to iterate through and keep a stack of the (uncrushed) candy, popping and setting as we iterate through the row in reverse order.

        //Alternatively, we could use a sliding window approach, maintaining a read and write head.
        //As the read head iterates through the row in reverse order, when the read head sees candy, the write head will write it down and move one place.
        //Then, the write head will write zeroes to the remainder of the row.
        for(int j = 0; j < m; j++){
            int write_head = n - 1;
            for(int read_head = n - 1; read_head >= 0; read_head--){
                if(board[read_head][j] > 0)
                    board[write_head--][j] = board[read_head][j];
            }
            while(write_head >= 0)
                board[write_head--][j] = 0;
        }
    }
public:
    //It's O((R*C)^2) complexity because each function call scans the board three times so it's 3(R*C). If we only crush 3 candies each time, the function will be called (R*C)/3 times. Multiply those two terms together you get O((R*C)^2)
    vector<vector<int>> candyCrush(vector<vector<int>>& board) {
        this -> n = board.size();
        this -> m = board[0].size();
        bool found_crush = mark_candies_to_crush(board);
        percolate_candies(board);
        return found_crush ? candyCrush(board) : board;
    }
};