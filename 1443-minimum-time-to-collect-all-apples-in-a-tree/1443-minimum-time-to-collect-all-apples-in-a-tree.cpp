class Solution {
private:
    unordered_map<int, vector<int>> tree;
    unordered_set<int> visited;
    int root_node = 0;
    void build_tree(vector<vector<int>>& edges){
        tree.clear();
        visited.clear();
        for(vector<int> edge : edges){
            tree[edge[0]].push_back(edge[1]);
            tree[edge[1]].push_back(edge[0]);    
        }
    }
    int get_min_time(int curr_node, vector<bool>& has_apple){
        int time = 0;
        for(int child_node : tree[curr_node]){
            if(visited.find(child_node) == visited.end()){
                visited.insert(child_node);
                time += get_min_time(child_node, has_apple);
            }
        }
        if((time > 0 || has_apple[curr_node]) && curr_node != root_node)
            time += 2;
         return time;   
    }
    // You need to consume 2 seconds to simply collect an apple node (come and go)
    // Consider a node:
    // If none of descendant (including itself) has an apple, we don't need to waste time on this node
    // If any of descendant has an apple (no matter if it-self has an apple or not), we need to consume 2 seconds on this node anyway
    // Collect node 0 does not need to consume any time

public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        build_tree(edges);
        visited.insert(root_node);
        return get_min_time(root_node, hasApple);
    }
};