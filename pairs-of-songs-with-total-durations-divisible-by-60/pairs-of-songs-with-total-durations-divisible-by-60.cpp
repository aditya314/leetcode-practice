class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int n = time.size();
        unordered_map<int, int> time_mod_count;
        int pair_cout = 0;
        for(int duration : time){
            int time_mod = duration % 60;
            if(time_mod == 0){
                pair_cout += (time_mod_count[0]);
            }   
            else {
                int complementary_mod = 60 - time_mod;
                pair_cout += (time_mod_count[complementary_mod]);
            }
            time_mod_count[(duration % 60)]++;
        }
        return pair_cout;
    }
};