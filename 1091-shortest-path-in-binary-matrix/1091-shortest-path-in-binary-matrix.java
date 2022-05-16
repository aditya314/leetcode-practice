class Solution {
    public int shortestPathBinaryMatrix(int[][] grid) {
        if(grid == null || grid.length == 0 || grid[0][0] == 1)    return -1;
        
        ArrayDeque<int[]> q = new ArrayDeque<>();
        //{x, y, dis}
        q.add(new int[] {0, 0, 0});
        while(!q.isEmpty()){
            int[] currNode = q.remove();
            int x = currNode[0], y = currNode[1], dis = currNode[2];
            if(x == grid.length - 1 && y == grid[0].length - 1)
                return dis + 1;
            for(int k = 0; k < directionCount; k++){
                int i = x + dx[k];
                int j = y + dy[k];
                if(i < 0 || j < 0 || i >= grid.length || j >= grid[0].length || grid[i][j] != 0)
                    continue;
                grid[i][j] = -1;
                q.add(new int[] {i, j, dis + 1});
            }
        }
        return -1;
    }
    private static final int directionCount = 8;
    private static final int[] dx = new int[] {0, 1, -1, 0, 1, -1, 1,-1};
    private static final int[] dy = new int[] {1, 0, 0, -1, 1, 1, -1, -1};
    
}