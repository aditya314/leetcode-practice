class Solution {
private:
    void backtrack_solution(vector<int>& candidates, int target, int i, vector<int> combo, vector<vector<int>>& answer){
        if(i == candidates.size()){
            if(target == 0){
                answer.push_back(combo);
                return;
            }
            return;
        }
        if(target < 0)  return;
        combo.push_back(candidates[i]);
        backtrack_solution(candidates, target - candidates[i], i, combo, answer);
        combo.pop_back();
        backtrack_solution(candidates, target, i + 1, combo, answer);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> answer;
        vector<int> combo;
        backtrack_solution(candidates, target, 0, combo, answer);
        return answer;
    }
};