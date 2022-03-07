class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        if(changed.size() % 2 == 1) 
            return {};
        unordered_map<int, int> num_freq;
        for (int a : changed) 
            num_freq[a]++;
        
        vector<int> unique_keys;
        for (pair<int, int> it : num_freq)
            unique_keys.push_back(it.first);
        sort(unique_keys.begin(), unique_keys.end(), [](int i, int j) {return abs(i) < abs(j);});
        
        vector<int> answer;
        for (int x : unique_keys) {
            if (num_freq[x] > num_freq[2 * x])
                return {};
            int i = 0;
            while(i < num_freq[x]){
                answer.push_back(x);
                num_freq[2 * x]--;
                i++;
            }
        }
        return answer;
    }
};