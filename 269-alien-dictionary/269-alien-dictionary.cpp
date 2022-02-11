class Solution {
private:
    pair<char, char> get_lexico_relation(string& a, string& b){
        int k = 0, n = a.length(), m = b.length();
        while(k < min(n, m)){
            if(a[k] != b[k])    return {a[k], b[k]};
            k++;
        }
        return {'*','*'};
    }
    void init_graph(unordered_map<char, vector<char>>& graph, unordered_map<char, int>& indegree, vector<string>& words){
        for(string word :  words){
            for(char ch :  word){
                if(graph.find(ch) == graph.end())   graph[ch] = {};
                if(indegree.find(ch) == indegree.end())   indegree[ch] = 0;
            }
        }
    }
    bool is_prefix(string& a, string& b){
       return (a.length() > b.length() && a.find(b) == 0); 
    }
public:
    string alienOrder(vector<string>& words) {
        int n = words.size();
        unordered_map<char, vector<char>> graph;
        unordered_map<char, int> indegree;
        init_graph(graph, indegree, words);
        for(int i = 0; i <= n - 2; i++){
            //invalid dict
            if(is_prefix(words[i], words[i + 1]))    return "";
               
            pair<char, char> lexico_relation = get_lexico_relation(words[i], words[i + 1]);
            if(lexico_relation.first == '*' && lexico_relation.second == '*')   continue;
            graph[lexico_relation.first].push_back(lexico_relation.second);
            indegree[lexico_relation.second]++;
        }
        
        //cout<<graph.size()<<"*"<<indegree.size()<<endl;
        queue<char> q;
        for(pair<char, int> char_indegree : indegree)
            if(char_indegree.second == 0)
                q.push(char_indegree.first);
        
        string answer = "";
        while(!q.empty()){
            char parent_char = q.front();
            q.pop();
            answer = answer + parent_char;
            for(char ch : graph[parent_char]){
                indegree[ch]--;
                if(indegree[ch] == 0)
                    q.push(ch);
            }
        }
        
        if(answer.length() != graph.size())  return "";
        return answer;
    }
};