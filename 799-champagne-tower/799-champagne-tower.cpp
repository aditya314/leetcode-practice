class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<double>> glasses(query_row + 2, vector<double>(query_row + 2, 0.0));
        glasses[0][0] = (double) poured;
        for(int i = 0; i <= query_row; i++){
            for(int j = 0; j <= i; j++){
                double spilled_wine = (glasses[i][j] - 1.0) / 2.0;
                if(spilled_wine > 0){
                    glasses[i + 1][j] += spilled_wine;
                    glasses[i + 1][j + 1] += spilled_wine;
                }
            }
        }
        return min(1.0, glasses[query_row][query_glass]);
    }
};