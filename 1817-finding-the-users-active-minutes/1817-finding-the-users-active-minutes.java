class Solution {
    public int[] findingUsersActiveMinutes(int[][] logs, int k) {
        int[] UAM = new int[k];
        HashMap<Integer, HashSet<Integer> > userLoginMap = new HashMap<>();
        for(int[] log : logs){
            userLoginMap.putIfAbsent(log[0], new HashSet<>());
            userLoginMap.get(log[0]).add(log[1]);
        }
        for(int userId : userLoginMap.keySet()){
            UAM[userLoginMap.get(userId).size() - 1]++;
        }
        return UAM;
    }
}