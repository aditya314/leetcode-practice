class Solution {
    //naive approach
    //For every move, we need to traverse the same row, column, diagonal, and       //anti-diagonal, which takes O(n) time.
    //total time O(n * m) where n is board size and m is moves
    //space O(n ^ 2) for storing every move
    
    //efficient approach
    //time O(m)
    //space O(n)
private:
    const int board_size = 3;
    bool is_point_on_diagonal(int x, int y){
        return (x == y);
    }
    bool is_point_on_anti_diagonal(int x, int y){
        return (x + y == board_size - 1);
    }
public:
    string tictactoe(vector<vector<int>>& moves) {
        vector<int> row_result(board_size), col_result(board_size);
        int diagonal_result = 0, anti_diagonal_result = 0;
        int player_move = 1;
        
        for(vector<int> &move : moves){
            row_result[move[0]] += player_move;
            col_result[move[1]] += player_move;
            if(is_point_on_diagonal(move[0], move[1]))
                diagonal_result += player_move;
            if(is_point_on_anti_diagonal(move[0], move[1]))
                anti_diagonal_result += player_move;
            
            if(abs(row_result[move[0]]) == board_size ||
                  abs(col_result[move[1]]) == board_size ||
                    abs(diagonal_result) == board_size ||
                        abs(anti_diagonal_result) == board_size)
                return (player_move == 1) ? "A" : "B";
            
            //change player move
            player_move *= -1;
        }
        
        return (moves.size() == board_size * board_size) ? "Draw" : "Pending";
    }
};