class Solution {
private: 
    bool is_magnetic_force_valid(vector<int>& position, int m, int n, int force){
        int ball_count = 1, prev = position[0];
        for(int i = 1; i < n; i++){
            if((position[i] - prev >= force)){
                prev = position[i];
                ball_count++;
            } 
        }
        return (ball_count >= m);
    }
public:
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int n = position.size();
        int low = 0, high = position[n - 1] - position[0];
        int answer = INT_MIN;
        while(low <= high){
            int mid = low + ((high - low) >> 1);
            if(is_magnetic_force_valid(position, m, n, mid)){
                answer = max(answer, mid);
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        return answer;
    }
};