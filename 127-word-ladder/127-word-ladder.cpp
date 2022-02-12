class Solution {
private:
    int answer = INT_MAX;
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
    int hop_from_node(queue<string>& q, unordered_map<string, int>& visited_level, unordered_map<string, int>& other_visited_level, vector<string>& word_list){
        string parent_string = q.front();
        cout<<"For word :"<<parent_string<<endl;
        q.pop();
        int level = visited_level[parent_string];
        for(int j = 0; j < parent_string.length(); j++){
            char ch = parent_string[j];
            parent_string[j] = '*';
            for(int child_index : transformation_graph[parent_string]){
                string child_word = word_list[child_index];
                if(other_visited_level.find(child_word) != other_visited_level.end()){
                    this->answer = min(this->answer, level + other_visited_level[child_word]);
                    // return level + other_visited_level[child_word];
                }if(visited_level.find(child_word) == visited_level.end()){
                    visited_level[child_word] = level + 1;
                    q.push(child_word);
                }
            }
            parent_string[j] = ch;
        }
        return 0;
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
            answer = hop_from_node(q_begin, visited_level_begin, visited_level_end, word_list);
            cout<<answer<<endl;
            if(answer > 0) return answer;
            answer = hop_from_node(q_end, visited_level_end, visited_level_begin, word_list);
            cout<<answer<<endl;
            if(answer > 0) return answer;
        }
        return 0;
    }
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if(find(wordList.begin(), wordList.end(), endWord) == wordList.end())
            return 0;
        this->answer = INT_MAX;
        //regex -> index in array for possible tranformation
        transformation_graph.clear();
        build_transformation_graph(wordList);
        print_graph();
        get_length_bidirectional_bfs(beginWord, endWord, wordList);
        return this->answer == INT_MAX ? 0: this->answer;
    }
};