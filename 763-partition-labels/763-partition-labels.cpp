class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, int> last_pos;
        for(int i = 0; i < s.length(); i++)
            last_pos[s[i]] = i;
        
        vector<int> partitions;
        int prev_partition_index = 0, curr_partition_index = 0;
        for(int i = 0; i < s.length(); i++){
            if(last_pos[s[i]] > curr_partition_index)
                curr_partition_index = last_pos[s[i]];
            if(i == curr_partition_index){
                int substring_length = curr_partition_index - prev_partition_index + 1;
                partitions.push_back(substring_length);
                prev_partition_index = i + 1;
            }
        }
        return partitions;
    }
};