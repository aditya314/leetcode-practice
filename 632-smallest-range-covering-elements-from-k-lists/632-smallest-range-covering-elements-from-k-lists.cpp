class ListItem{
public:
    int val, row, col;
    ListItem(int val, int row, int col){
        this -> val = val;
        this -> row = row;
        this -> col = col;
    }
};
struct ListItemComparator{
    bool operator()(ListItem& a, ListItem& b){
        return (a.val > b.val);
    }
};
class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue<ListItem, vector<ListItem>, ListItemComparator> min_heap;
        int range_max = INT_MIN;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            min_heap.push(ListItem(nums[i][0], i, 0));
            range_max = max(range_max, nums[i][0]);
        }
        int range_min = min_heap.top().val;
        vector<int> range{range_min, range_max};
        while(min_heap.size() == n){
            ListItem curr_min = min_heap.top();
            min_heap.pop();
            if(curr_min.col + 1 < nums[curr_min.row].size()){
                int next_max = nums[curr_min.row][curr_min.col + 1];
                min_heap.push(ListItem(next_max, curr_min.row, curr_min.col + 1));
                range_max = max(range_max, next_max);
                range_min = min_heap.top().val;
                if(range[1] - range[0] > range_max - range_min){
                    range[0] = range_min;
                    range[1] = range_max;
                }
            }
        }
        return range;
    }
};