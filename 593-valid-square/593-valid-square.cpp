class Solution {
private:
    const int total_points = 4;
    int get_distance_square(vector<int>& p1, vector<int>& p2){
        return (p2[1] - p1[1]) * (p2[1] - p1[1]) + (p2[0] - p1[0]) * (p2[0] - p1[0]);
    }
    bool is_square(vector<vector<int>>& points){
        int side_A_square = get_distance_square(points[0], points[1]);
        int side_B_square = get_distance_square(points[1], points[2]);
        int side_C_square = get_distance_square(points[2], points[3]);
        int side_D_square = get_distance_square(points[3], points[0]);
        int diagonal_M_square = get_distance_square(points[0], points[2]);
        int diagonal_N_square = get_distance_square(points[1], points[3]);
        return  side_A_square > 0 && diagonal_N_square > 0 
                && side_A_square == side_B_square
                    && side_B_square == side_C_square
                        && side_C_square == side_D_square
                && diagonal_M_square == diagonal_N_square;
            
    }
    bool is_valid_square_permute(vector<vector<int>>& points, int i){
        if(i == total_points)
            return is_square(points);
        for(int j = i; j < total_points; j++){
            swap(points[i], points[j]);
            if(is_valid_square_permute(points, i + 1))  return true;
            swap(points[i], points[j]);
        }
        return false;
    }
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        vector<vector<int>> points = {p1, p2, p3, p4};
        return is_valid_square_permute(points, 0);
    }
};