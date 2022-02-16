class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        unordered_map<int, int> num_freq;
        for (int a : arr) 
            num_freq[a]++;
        
        vector<int> keys;
        for (pair<int, int> it : num_freq)
            keys.push_back(it.first);
        sort(keys.begin(), keys.end(), [](int i, int j) {return abs(i) < abs(j);});
        
        for (int x : keys) {
            if (num_freq[x] > num_freq[2 * x])
                return false;
            num_freq[2 * x] -= num_freq[x];
        }
        return true;
    }
};