class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), m = matrix[0].size();
        int low = 0, high = n * m - 1;
        while(low <= high){
            int mid = low + (high - low) / 2;
            int pivot_element = matrix[mid / m][mid % m];
            if(pivot_element < target)
                low = mid + 1;
            else if(pivot_element > target)
                high = mid - 1;
            else 
                return true;
        }
        return false;
    }
};