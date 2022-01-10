class Solution {
private:
    vector<int> prefix_weights;
public:
    Solution(vector<int>& w) {
        for(int weight :  w)    prefix_weights.push_back(weight);
        for(int i = 1; i < prefix_weights.size(); i++){
            prefix_weights[i] += prefix_weights[i - 1];
        }
    }
    
    int pickIndex() {
        float random_fraction = (float) rand() / RAND_MAX;
        float target_random_number = random_fraction * prefix_weights[prefix_weights.size() -1];
        return upper_bound(prefix_weights.begin(), prefix_weights.end(), target_random_number) - prefix_weights.begin();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */