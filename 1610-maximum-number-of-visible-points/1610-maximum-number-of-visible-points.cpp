class Solution {
private:
    const double PI = acos(-1.0);
    //EPS is epsilon. The "close-enough" factor.
    const double EPS = 1e-9;
    
    double get_angle_from_point_in_degrees(int x2, int y2, int x1, int y1){
        double dy = y2 - y1, dx = x2 - x1;
        double angle_in_degrees = atan2(dy, dx) * 180.0 / PI;
        return angle_in_degrees;
    }
public:
    int visiblePoints(vector<vector<int>>& points, int angle, vector<int>& location) {
        int visible_points_count = 0;
        vector<double> point_angles;
        for(vector<int> point : points){
            if(point[0] == location[0] && point[1] == location[1])
                visible_points_count++;
            else
                point_angles.push_back(get_angle_from_point_in_degrees(point[0], point[1], location[0], location[1]));
        }
        
        sort(point_angles.begin(), point_angles.end());
        // push the angles again by adding 360 to handle the case of consecutive points being after a complete cycle. ex - 345 and 14 (if angle >= 29)
        int n = point_angles.size();
        for(int i = 0; i < n; i++)
            point_angles.push_back(point_angles[i] + 360.0);
        
        int start = 0, end = 0, max_visible = 0;
        n = point_angles.size();
        while(end < n){
            while((point_angles[end] - point_angles[start] - angle) >= EPS)
                start++;
            max_visible = max(max_visible, end - start + 1);
            end++;
        }
        visible_points_count += max_visible;
        return visible_points_count;
    }
};