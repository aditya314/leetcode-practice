class Solution {
private:
    bool are_diagonal_points(int x1, int y1, int x2, int y2){
        return (x1 != x2 && y1 != y2);
    }
    bool has_complimentary_y_point(unordered_map<int, unordered_set<int>>& x_y_set_map, int x, int y){
        return (x_y_set_map[x].find(y) != x_y_set_map[x].end());
    }
public:
    int minAreaRect(vector<vector<int>>& points) {
        unordered_map<int, unordered_set<int>> x_y_set_map;
        for(vector<int>& point : points)
            x_y_set_map[point[0]].insert(point[1]);
        
        int min_area = INT_MAX, n = points.size();
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                int x1 = points[i][0], y1 = points[i][1];
                int x2 = points[j][0], y2 = points[j][1];
                if(are_diagonal_points(x1, y1, x2, y2)){
                    if(has_complimentary_y_point(x_y_set_map, x1, y2)
                        && has_complimentary_y_point(x_y_set_map, x2, y1)){
                        min_area = min(min_area, abs(x2 - x1) * abs(y2 - y1));
                    }
                }
            }
        }
        return (min_area != INT_MAX) ? min_area : 0;
    }
};