class Solution {
    public int networkDelayTime(int[][] times, int n, int k) {
        //build graph
        for(int[] time :  times){
            int source = time[0], destination = time[1], travelTime = time[2];
            graph.putIfAbsent(source, new ArrayList<>());
            graph.get(source).add(new Pair(travelTime, destination));
        }

        int[] minTime = new int[n + 1];
        Arrays.fill(minTime, Integer.MAX_VALUE);
        
        PriorityQueue<Pair<Integer, Integer>> pq = new PriorityQueue<Pair<Integer, Integer>>
                                                    ((a, b) -> (a.getKey() - b.getKey()));
        pq.add(new Pair(0, k));
        minTime[k] = 0;
        //start Dijkstra's
        while(!pq.isEmpty()){
            Pair<Integer, Integer> currParent = pq.remove();
            int currTime = currParent.getKey();
            int currNode = currParent.getValue();
            
            if(currTime > minTime[currNode] || !graph.containsKey(currNode))
                continue;
            for(Pair<Integer, Integer> edge : graph.get(currNode)){
                int travelTime = edge.getKey();
                int neighbourNode = edge.getValue();
                if(minTime[neighbourNode] > currTime + travelTime){
                    minTime[neighbourNode] = currTime + travelTime;
                    pq.add(new Pair(minTime[neighbourNode], neighbourNode));
                }
            }
        }
        
        //find node with max delay
        int maxDelay = Integer.MIN_VALUE;
        for(int i = 1; i <= n; i++)
            maxDelay = Math.max(maxDelay, minTime[i]);
        
        return (maxDelay == Integer.MAX_VALUE) ? -1 : maxDelay;
    }
    //Time complexity: O(N+ElogN)
    //Space complexity:O(N+E)
    private Map<Integer, List<Pair<Integer, Integer>>> graph = new HashMap<>();
}