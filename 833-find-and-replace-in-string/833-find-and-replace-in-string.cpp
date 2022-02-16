class Solution {
public:
    string findReplaceString(string s, vector<int>& indices, vector<string>& sources, vector<string>& targets) {
        unordered_map<int, int> string_index_operation_map;
        //mapping of valid string index vs operation index
        int total_operations = indices.size();
        for(int operation_index = 0; operation_index < total_operations; operation_index++){
            if(s.substr(indices[operation_index], sources[operation_index].length())
                    == sources[operation_index])
                string_index_operation_map[indices[operation_index]] = operation_index;
        }
        
        string answer = "";
        for(int i = 0; i < s.length();){
            if(string_index_operation_map.find(i) != string_index_operation_map.end()){
                answer += targets[string_index_operation_map[i]];
                i += sources[string_index_operation_map[i]].length();
            }
            else{
                answer += s[i];
                i++;
            }
        }
        return answer;
    }
};