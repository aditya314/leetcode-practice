class Solution {
    //Time: O(2 ^ (n * m))
private:
    int n, m;
    int di[4] = {0, 1, 0, -1};
    int dj[4] = {1, 0, -1, 0};
    bool all_zeroes(vector<vector<int>>& mat){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(mat[i][j])  return false;
            }
        }
        return true;
    }
    bool is_valid(int i, int j){
        return (i >= 0 && i < n && j >= 0 && j < m);
    }
    void flip_cell(vector<vector<int>>& mat, int i, int j){
        mat[i][j] = mat[i][j] ^ 1;
        for(int k = 0; k < 4; k++){
            int x = i + di[k];
            int y = j + dj[k];
            if(is_valid(x, y))
                mat[x][y] = mat[x][y] ^ 1;
        } 
        //cout<<"flipped "<<i<<"," <<j<<endl;
        // for(int i = 0; i < n; i++){
        //     for(int j = 0; j < m; j++){
        //         cout<<mat[i][j]<<",";
        //     }
        //     cout<<endl;
        // }
    }
    int get_min_on_cell_flip_backtrack(vector<vector<int>>& mat, int i, int j){
        //cout<<"For "<<i<<" ,"<<j<<"trying"<<endl;
        if(j == m){
            i++;
            j = 0;
        }
        if(i == n)
            return all_zeroes(mat) ? 0 : INT_MAX;  
        int count_if_cell_not_flipped = get_min_on_cell_flip_backtrack(mat, i, j + 1);
        flip_cell(mat, i, j);
        int count_if_cell_flipped = get_min_on_cell_flip_backtrack(mat, i, j + 1);
        if(count_if_cell_flipped != INT_MAX)
            count_if_cell_flipped++;
        flip_cell(mat, i, j);
        return min(count_if_cell_not_flipped, count_if_cell_flipped);
    }
public:
    int minFlips(vector<vector<int>>& mat) {
        this -> n = mat.size();
        this -> m = mat[0].size();
        int min_flip_count = get_min_on_cell_flip_backtrack(mat, 0, 0);
        return (min_flip_count != INT_MAX) ? min_flip_count : -1; 
    }
};

