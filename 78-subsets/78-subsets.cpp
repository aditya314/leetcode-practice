class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        //cascading method to try smth new
        //N*2^N 
        //same as backtarcking
        vector<vector<int>> answer;
        answer.push_back({});
        for(int num : nums){
            //can iterate ahead if duplicates
            vector<vector<int>> new_subsets;
            for(vector<int> curr_set : answer){
                curr_set.push_back(num);
                new_subsets.push_back(curr_set);
                //needed if curr_set is pass by reference, thanks to c++ it is not
                //curr_set.pop_back();
            }
            answer.insert(answer.end(), new_subsets.begin(), new_subsets.end());
        }
        return answer;
    }
};