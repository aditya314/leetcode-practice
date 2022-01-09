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
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        DSU disjoint_set(1001);
        for(vector<int> edge : edges){
            if(!disjoint_set.unite(edge[0], edge[1]))   return edge;
        }
        return vector<int>();
    }
};

