class Solution {
private:
    void get_child_process(unordered_map<int, vector<int>>& process_graph,
                           vector<int>& killed_process, int kill){
        for(int child_process : process_graph[kill]){
            killed_process.push_back(child_process);
            get_child_process(process_graph, killed_process, child_process);
        }
    }
public:
    vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
        unordered_map<int, vector<int>> process_graph;
        for(int i = 0; i < ppid.size(); i++){
            if(ppid[i] > 0)
                process_graph[ppid[i]].push_back(pid[i]);    
        }
        vector<int> killed_process;
        killed_process.push_back(kill);
        get_child_process(process_graph, killed_process, kill);
        return killed_process;
    }
};