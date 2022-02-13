class Solution {
private:
    unordered_map<string, vector<int>> transformation_graph;
    void build_transformation_graph(vector<string>& wordList){
        for(int i = 0; i < wordList.size(); i++){
            for(int j = 0; j < wordList[i].length(); j++){
                char ch = wordList[i][j];
                wordList[i][j] = '*';
                transformation_graph[wordList[i]].push_back(i);
                wordList[i][j] = ch;
            }
        }
    }
    void print_graph(){
        cout<<"The graph is "<<endl;
        for(pair<string, vector<int> > x : transformation_graph){
            cout<<x.first<<"->";
            for(int i : x.second)   cout<<i<<",";
            cout<<endl;
        }
    }
    int bfs_one_layer(queue<string>& q, unordered_map<string, int>& visited_level, unordered_map<string, int>& other_visited_level, vector<string>& word_list){
        for(int i = 0; i < q.size(); i++){
            string parent_string = q.front();
            q.pop();
            int level = visited_level[parent_string];
            for(int j = 0; j < parent_string.length(); j++){
                char ch = parent_string[j];
                parent_string[j] = '*';
                for(int child_index : transformation_graph[parent_string]){
                    string child_word = word_list[child_index];
                    if(other_visited_level.find(child_word) != other_visited_level.end())
                        return level + other_visited_level[child_word];
                    if(visited_level.find(child_word) == visited_level.end()){
                        visited_level[child_word] = level + 1;
                        q.push(child_word);
                    }

                }
                parent_string[j] = ch;
            }
        }
        return -1;
    }
    int get_length_bidirectional_bfs(string& begin_word, string& end_word, vector<string>& word_list){
        queue<string> q_begin, q_end;
        q_begin.push(begin_word);
        q_end.push(end_word);
        
        unordered_map<string, int> visited_level_begin, visited_level_end;
        visited_level_begin[begin_word] = 1;
        visited_level_end[end_word] = 1;
        
        int answer = 0;
        while(!q_begin.empty() && !q_end.empty()){
            if(q_begin.size() <= q_end.size())
                answer = bfs_one_layer(q_begin, visited_level_begin, visited_level_end, word_list);
            else
                answer = bfs_one_layer(q_end, visited_level_end, visited_level_begin, word_list);
            if(answer != -1) return answer;
        }
        return 0;
    }
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if(find(wordList.begin(), wordList.end(), endWord) == wordList.end())
            return 0;
        //regex -> index in array for possible tranformation
        transformation_graph.clear();
        build_transformation_graph(wordList);
        print_graph();
        return get_length_bidirectional_bfs(beginWord, endWord, wordList);
    }
};