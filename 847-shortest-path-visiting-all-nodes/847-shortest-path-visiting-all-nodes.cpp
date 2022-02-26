class NodeState{
private:
    const int prime = 101;
public:
    int node, visited_node_bitmask;
    NodeState(int node, int visited_node_bitmask){
        this -> node = node;
        this -> visited_node_bitmask = visited_node_bitmask;
    }
    string get_hash_code(){
        return to_string(this -> node) + to_string(this -> visited_node_bitmask);
    }
};
class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        if(n <= 1)  return 0;
        queue<NodeState*> q;
        unordered_set<string> seen_state;
        for(int i = 0; i < n; i++){
            NodeState* source_state = new NodeState(i, 1 << i);
            q.push(source_state);
            seen_state.insert(source_state -> get_hash_code());
        }
        int path_length = 0;
        int all_visited_bitmask = (1 << n) - 1;
        while(!q.empty()){
            int q_size = q.size();
            for(int i = 0; i < q_size; i++){
                NodeState* parent_state = q.front();
                q.pop();
                int parent_visited_node_bitmask = parent_state -> visited_node_bitmask; 
                if(parent_visited_node_bitmask == all_visited_bitmask)
                        return path_length;
                    
                for(int child : graph[parent_state -> node]){
                    int child_visited_node_bitmask = parent_visited_node_bitmask | (1 << child); 
                    NodeState* child_node_state = new NodeState(child, child_visited_node_bitmask);
                    string child_hash_code = child_node_state -> get_hash_code();
                    if(seen_state.find(child_hash_code) == seen_state.end()){
                        seen_state.insert(child_hash_code);
                        q.push(child_node_state);
                    }
                }
            }
            path_length++;
        }
        return path_length;
    }
};