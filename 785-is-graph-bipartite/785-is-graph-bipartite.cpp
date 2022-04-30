class Solution {
private:
    enum colour {WHITE, RED, GREEN};
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<colour> colours(n, WHITE);
        
        queue<int> q;
        for(int i = 0; i < n; i++){
            if(colours[i] != WHITE)
                continue;
            colours[i] = RED;
            q.push(i);
            while(!q.empty()){
                int node = q.front();
                q.pop();
                for(int neighbour : graph[node]){
                    if(colours[neighbour] == WHITE){
                        colours[neighbour] = (colours[node] == GREEN) ? RED : GREEN;
                        q.push(neighbour);
                    }
                    else if(colours[neighbour] == colours[node])
                        return false;
                }
            }
        }
        return true;
    }
};