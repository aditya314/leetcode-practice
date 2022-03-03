/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    Node* cloneTree(Node* root) {
        if(!root)   return root;
        Node* node_copy = new Node(root -> val);
        for(Node* child : root -> children)
            node_copy->children.push_back(this -> cloneTree(child));
        return node_copy;
    }
};