class Solution {    
public:
    static bool point_comparator(vector<int>& point1, vector<int>& point2){
        return (point1[1] == point2[1]) ? (point1[0] < point2[0]) : (point1[1] < point2[1]);
    }
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), point_comparator);
        int i = 0, n = points.size(), answer = 0;
        while(i < n){
            int j = i + 1;
            while(j < n && (points[i][1] >= points[j][0]))      j++; 
            answer++;
            i = j;
        }
        return answer;
    }
};