class Solution {
private:
    int get_max_time(unordered_map<int,vector<int>>& graph, int node, vector<int>& inform_time){
        if(graph.find(node) == graph.end())	return 0;
        int max_time = 0;
        for(int employee : graph[node])
            max_time = max(max_time, get_max_time(graph, employee, inform_time));
        max_time += inform_time[node];
        return max_time;
    }
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        unordered_map<int,vector<int>> graph;
        for(int i = 0; i < n; i++)
            graph[manager[i]].push_back(i);
        return get_max_time(graph, headID, informTime);
    }
};

