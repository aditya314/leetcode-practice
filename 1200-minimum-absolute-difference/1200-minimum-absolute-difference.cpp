class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        int n = arr.size(), min_diff = INT_MAX;
        sort(arr.begin(), arr.end());
        vector<vector<int>> answer;
        for(int i = 0; i < n - 1; i++){
            int curr_diff = arr[i + 1] - arr[i];
            if(curr_diff < min_diff){
                answer.clear();
                answer.push_back({arr[i], arr[i + 1]});
                min_diff = arr[i + 1] - arr[i];
            }
            else if(curr_diff == min_diff){
                answer.push_back({arr[i], arr[i + 1]});
            }
        }
        return answer;
    }
};