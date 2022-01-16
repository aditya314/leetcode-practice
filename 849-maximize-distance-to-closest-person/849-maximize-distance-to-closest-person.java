class Solution {
    public int maxDistToClosest(int[] seats) {
        int lastSeenPersonIndex = -1;
        int maxDistance = 1;
        int n = seats.length;
        for(int i = 0; i < n; i++){
            if(seats[i] == 1){
                maxDistance = Math.max(maxDistance, (lastSeenPersonIndex == -1) ? i : ((i - lastSeenPersonIndex) / 2));
                //System.out.println("For i = " + i + " lastSeenPersonIndex = " + lastSeenPersonIndex + " maxDistance = " + maxDistance);
                lastSeenPersonIndex = i;
            }
        }
        maxDistance = Math.max(maxDistance, n - lastSeenPersonIndex - 1);
        return maxDistance;
    }
}