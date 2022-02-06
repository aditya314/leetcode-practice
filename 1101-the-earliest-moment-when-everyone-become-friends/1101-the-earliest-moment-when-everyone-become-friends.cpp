class DSU{
    private:
    vector<int> parent;
    vector<int> rank;
    int sets_count;
    
    public:
    DSU(int n){
        for(int i = 0; i < n; i++)     parent.push_back(i);
        rank = vector<int>(n, 0);
        sets_count = n;
    }
    
    int find(int node){
        if(parent[node] != node)  parent[node] = find(parent[node]);
        return parent[node];
    }
    
    bool unite(int node_a, int node_b){
        int parent_a = find(node_a), parent_b = find(node_b);
        if(parent_a == parent_b)    return false;
        if(rank[parent_a] < rank[parent_b])
            parent[parent_a] = parent_b; 
        else if(rank[parent_a] > rank[parent_b])
            parent[parent_b] = parent_a;
        else{
            rank[parent_a]++;
            parent[parent_b] = parent_a;
        }
        sets_count--;
        return true;
    } 
    
    int get_sets_count(){
        return sets_count;
    }
    
};
class Solution {
public:
    int earliestAcq(vector<vector<int>>& logs, int n) {
        sort(logs.begin(), logs.end());
        DSU dsu(n);
        for(vector<int> log : logs){
            int timestamp = log[0], friend_a = log[1], friend_b = log[2];
            dsu.unite(friend_a, friend_b);
            if(dsu.get_sets_count() == 1)  return timestamp;
        }
        return -1;
    }
};