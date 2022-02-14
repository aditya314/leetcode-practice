class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if(source == target)     return 0;
        unordered_map<int, vector<int> > bus_stop_routes;
        for(int i = 0; i < routes.size(); i++){
            for(int bus_stop : routes[i]){
                bus_stop_routes[bus_stop].push_back(i);
            }
        }
        
        queue<int> q;
        unordered_set<int> visited_routes_index;
        q.push(source);
        //all the bus stops at a given level, are "equal distance" from the start node, in terms of number of buses that need to be changed.
        int bus_count = 1;
        while(!q.empty()){
            int sz = q.size();
            for(int i = 0; i < sz; i++){
                int curr_bus_stop = q.front();
                q.pop();
                for(int route_index : bus_stop_routes[curr_bus_stop]){
                    if(visited_routes_index.find(route_index) == visited_routes_index.end()){
                        for(int bus_stop :  routes[route_index]){
                            if(bus_stop == target)  return bus_count;
                            q.push(bus_stop);
                        }   
                        visited_routes_index.insert(route_index);
                    } 
                }
            }
            bus_count++;
        }
        return -1;
    }
};
