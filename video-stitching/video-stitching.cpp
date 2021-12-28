
class Solution {
private:
    static bool clips_comparator(vector<int> clip_A, vector<int> clip_B){
        return (clip_A[0] != clip_B[0]) ? (clip_A[0] < clip_B[0]) : (clip_A[1] < clip_B[1]);
        //return (clip_A[0] < clip_B[0]);
    }
public:
    int videoStitching(vector<vector<int>>& clips, int time) {
        int clip_count = 0, n = clips.size();
        sort(clips.begin(), clips.end(), clips_comparator);
        //if(n > 0 && clips[n - 1][1] < time)  return -1;
        for(int i = 0, end = 0, max_reach = 0; end < time; end = max_reach){
            clip_count++;
            while(i < n && clips[i][0] <= end){
                max_reach = max(max_reach, clips[i][1]);
                i++;
            }
            if(end == max_reach)    return -1;
        }
        return clip_count;
    }
};