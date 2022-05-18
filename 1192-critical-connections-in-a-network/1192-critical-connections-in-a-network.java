class Solution {
    // We record the timestamp that we visit each node.
    //For each node, we check every neighbor except its parent and return a smallest timestamp in all its neighbors. 
    //If this timestamp is strictly less than the node's timestamp, we know that this node is somehow in a cycle.
    //Otherwise, this edge from the parent to this node is a critical connection

    public List<List<Integer>> criticalConnections(int n, List<List<Integer>> connections) {
        for(List<Integer> connection : connections){
            graph.putIfAbsent(connection.get(0), new ArrayList<>());
            graph.putIfAbsent(connection.get(1), new ArrayList<>());
            graph.get(connection.get(0)).add(connection.get(1));
            graph.get(connection.get(1)).add(connection.get(0));
        }
        
        int[] nodeTimestamp = new int[n];
        //-1 means not visited
        Arrays.fill(nodeTimestamp, -1);
        getCriticalConnection(0, -1, nodeTimestamp);
        return answer;
    }
    private void getCriticalConnection(int node, int parent, int[] nodeTimestamp){
        nodeTimestamp[node] = currTime++;
        int currTimestamp = nodeTimestamp[node];
        //if(!graph.containsKey(node))    return;
        
        for(int child : graph.get(node)){
            if(child == parent)                 continue;
            if(nodeTimestamp[child] == -1)      getCriticalConnection(child, node, nodeTimestamp);
            nodeTimestamp[node] = Math.min(nodeTimestamp[node], nodeTimestamp[child]);
            if(currTimestamp < nodeTimestamp[child])    
                answer.add(Arrays.asList(node, child));
        }
    }
    private List<List<Integer>> answer = new ArrayList<>();
    private HashMap<Integer, ArrayList<Integer>> graph = new HashMap<>();
    private static int currTime = 0;
}