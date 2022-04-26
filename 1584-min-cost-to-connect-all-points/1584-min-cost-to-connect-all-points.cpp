class DSU{
    private:
        vector<int> parent;
        vector<int> rank;
    public:
        DSU(int n){
            for(int i = 0; i < n; i++){
                parent.push_back(i);
                rank.push_back(0);
            }
        }
        int find(int x){
            if(parent[x] != x)
                parent[x] = find(parent[x]);
            return parent[x];
        }
        bool join(int x, int y){
            int x_rep = find(x);
            int y_rep = find(y);
            if(x_rep == y_rep)  return false;
            
            if(rank[x_rep] > rank[y_rep])
                parent[y_rep] = x_rep;
            else if(rank[x_rep] < rank[y_rep])
                parent[x_rep] = y_rep;
            else{
                parent[x_rep] = y_rep;
                rank[y_rep]++;
            }
            return true;
        }
};
class ManhattanEdge{
    public:
    int u, v, dis;
    ManhattanEdge(int u, int v, int dis){
        this -> u = u;
        this -> v = v;
        this -> dis = dis;
    }
};
    
class Solution {
private:
    static bool edge_comparator(ManhattanEdge& a, ManhattanEdge& b){
        return (a.dis < b.dis);
    }
    int get_manhattan_distance(vector<int>& point_a, vector<int>& point_b){
        return abs(point_a[0] - point_b[0]) + abs(point_a[1] - point_b[1]);
    }
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<ManhattanEdge> edges;
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                int dis = get_manhattan_distance(points[i], points[j]);
                ManhattanEdge edge(i, j, dis);
                edges.push_back(edge);
            }
        }
        sort(edges.begin(), edges.end(), edge_comparator);
        
        DSU dsu(n);
        int m = edges.size(), min_cost = 0, edges_used = 0;
        for(int i = 0; i < m && edges_used < n - 1; i++){         
            if(dsu.join(edges[i].u, edges[i].v)){
                min_cost += edges[i].dis;
                edges_used++;
            }
        }
        return min_cost;
    }
};