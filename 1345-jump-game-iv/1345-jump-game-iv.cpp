class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        if(n <= 1)  return 0;
        
        unordered_map<int, vector<int> > graph;
        for(int i = 0; i < n; i++)      graph[arr[i]].push_back(i);     
        
        queue<int> q;
        q.push(0);
        vector<bool> visited(n, false);
        visited[0] = true;
        
        int step = 0;
        while(!q.empty()){
            for (int i = q.size(); i > 0; i--) {
                int index = q.front();
                q.pop();
                if (index == n - 1)     return step;
                vector<int>& children = graph[arr[index]];
                children.push_back(index + 1);
                children.push_back(index - 1);
                for (int next_index : children) {
                    if (next_index >= 0 && next_index < n && !visited[next_index]) {
                        visited[next_index] = true;
                        q.push(next_index);
                    }
                }
                children.clear();
            }
            step++;
        }
        return -1;
    }
};