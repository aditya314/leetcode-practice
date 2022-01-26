class Solution {
public:
    int maxArea(vector<int>& height) {
        int max_area = 0, low = 0, high = height.size() - 1;
        while(low < high){
            if(height[low] < height[high]){
                max_area = max(max_area, height[low] * (high - low));
                low++;
            }
            else{
                max_area = max(max_area, height[high] * (high - low));
                high--;
            }
        }
        return max_area;
    }
};