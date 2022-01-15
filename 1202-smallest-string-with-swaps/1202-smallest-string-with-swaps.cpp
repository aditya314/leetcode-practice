class DSU{
private:
    vector<int> parent;
    vector<int> rank;
    
public:
    DSU(int n){
        parent = vector<int>(n);
        rank = vector<int>(n, 0);
        for(int i = 0; i < n; i++)  parent[i] = i;
    }
    
    int find(int x){
        if(parent[x] != x)  parent[x] = find(parent[x]);
        return parent[x];
    }
    
    bool unite(int x, int y){
        int x_rep = find(x), y_rep = find(y);
        if(x_rep == y_rep)  return false;
        if(rank[x_rep] < rank[y_rep]){
            parent[x_rep] = y_rep;
        }
        else if(rank[x_rep] > rank[y_rep]){
            parent[y_rep] = x_rep;
        }
        else{
            parent[y_rep] = x_rep;
            rank[x_rep]++;
        }
        return true;
    }
};

class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n = s.length();
        DSU dsu = DSU(n);
        for(vector<int> pair: pairs)    dsu.unite(pair[0], pair[1]);
        
        unordered_map<int, priority_queue<char, vector<char>, greater<char>> > rep_index_heap;
        for(int i = 0 ; i < n; i++){
            int rep_index = dsu.find(i);
            rep_index_heap[rep_index].push(s[i]);
        }
        
        string answer = "";
        for(int i = 0; i < n; i++){
            int rep_index = dsu.find(i);
            answer += rep_index_heap[rep_index].top();
            rep_index_heap[rep_index].pop();
        }
        
        return answer;
        
    }
};