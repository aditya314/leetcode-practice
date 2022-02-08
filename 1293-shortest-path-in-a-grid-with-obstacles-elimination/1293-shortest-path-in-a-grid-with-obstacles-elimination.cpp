class StepState{
private:
    const int prime = 101;
public:
    int row, col, steps, threshold;
    StepState(int row, int col, int steps, int threshold){
        this->row = row;
        this->col = col;
        this->steps = steps;
        this->threshold = threshold;
    }
    int get_hash_code(){
        return (this->row * prime * prime) + (this->col * prime) + this->threshold;
    }
    void print(){
        cout<<"row = "<<row<<" col = "<<col<<" steps = "<<steps<<" threshold = "<<threshold<<endl;
    }
};

class Solution {
private:
    int di[4] = {0, 1, 0, -1};
    int dj[4] = {1, 0, -1, 0};
    int get_manhatten_distance(int x1, int y1, int x2, int y2){
        return (abs(x1 - x2) + abs(y1 - y2));
    }
    bool is_valid(int x, int y, int n, int m){
        return (x >= 0 && x < n && y >= 0 && y < m);
    }
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size();
        int shortest_distance = get_manhatten_distance(n - 1, m - 1, 0, 0);
        if(k >= shortest_distance)
            return shortest_distance;
        
        queue<StepState> q;
        unordered_set<int> seen_step_state;
        StepState initial_state(0, 0, 0, k);
        q.push(initial_state);
        seen_step_state.insert(initial_state.get_hash_code());
        
        while(!q.empty()){
            StepState curr_state = q.front();
            q.pop();
            //curr_state.print();
            if(curr_state.row == n - 1 && curr_state.col == m - 1)
                return curr_state.steps;
            for(int dir = 0; dir < 4; dir++){
                int i = curr_state.row + di[dir];
                int j = curr_state.col + dj[dir];
                if(is_valid(i, j, n, m)){
                    int new_threshold = curr_state.threshold - grid[i][j];
                    StepState child_state(i, j, curr_state.steps + 1, new_threshold);
                    int child_hash_code = child_state.get_hash_code();
                    if(new_threshold >= 0 && 
                       seen_step_state.find(child_hash_code) == seen_step_state.end()){
                        q.push(child_state);
                        seen_step_state.insert(child_hash_code);
                    }
                }
            }
        }
        return -1;
    }
};