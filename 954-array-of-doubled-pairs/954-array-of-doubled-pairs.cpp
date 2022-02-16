class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        unordered_map<int, int> num_freq;
        for (int a : arr) 
            num_freq[a]++;
        
        vector<int> unique_keys;
        for (pair<int, int> it : num_freq)
            unique_keys.push_back(it.first);
        sort(unique_keys.begin(), unique_keys.end(), [](int i, int j) {return abs(i) < abs(j);});
        
        for (int x : unique_keys) {
            if (num_freq[x] > num_freq[2 * x])
                return false;
            num_freq[2 * x] -= num_freq[x];
        }
        return true;
    }
};