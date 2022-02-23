/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(!node)    return node;
        unordered_map<Node*, Node*> clone_map;
        queue<Node*> q;
        q.push(node);
        clone_map[node] = new Node(node -> val, {});
        while(!q.empty()){
            Node* u = q.front();
            q.pop();
            for(Node* v : u -> neighbors){
                if(clone_map.find(v) == clone_map.end()){
                    clone_map[v] = new Node(v -> val, {});
                    q.push(v);
                }
                clone_map[u]->neighbors.push_back(clone_map[v]);
            }
        }
        return clone_map[node];
    }
};