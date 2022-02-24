/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
private:
    Node* build_quad_tree(vector<vector<int>>& grid, int low_x, int low_y, int high_x, int high_y){
        if(low_x > high_x || low_y > high_y)
            return NULL;
        bool is_leaf = true;
        int node_val = grid[low_x][low_y];
        for(int i = low_x; i <= high_x; i++){
            for(int j = low_y; j <= high_y; j++){
                if(grid[i][j] != node_val){
                    is_leaf = false;
                    break;
                }
            }
        }
        if(is_leaf)
            return new Node(node_val == 1, is_leaf, NULL, NULL, NULL, NULL);
        int mid_x = low_x + (high_x - low_x) / 2;
        int mid_y = low_y + (high_y - low_y) / 2;
        Node* top_left = build_quad_tree(grid, low_x, low_y, mid_x, mid_y);
        Node* top_right = build_quad_tree(grid, low_x, mid_y + 1, mid_x, high_y);
        Node* bottom_left = build_quad_tree(grid, mid_x + 1, low_y, high_x, mid_y);
        Node* bottom_right = build_quad_tree(grid, mid_x + 1, mid_y + 1, high_x, high_y);
        return new Node(NULL, NULL, top_left, top_right, bottom_left, bottom_right);
    }
public:
    Node* construct(vector<vector<int>>& grid) {
        return build_quad_tree(grid, 0, 0, grid.size() - 1, grid[0].size() - 1);
    }
};