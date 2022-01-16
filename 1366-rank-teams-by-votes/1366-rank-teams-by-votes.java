class Solution {
    public String rankTeams(String[] votes) {
        HashMap<Character, ArrayList<Integer> > voteMap = new HashMap<>();
        int n = votes[0].length();
        for(String s : votes){
            for(int pos = 0; pos < n; pos++){
                char ch = s.charAt(pos);
                ArrayList<Integer> positionVoteCount = voteMap.get(ch);
                if(positionVoteCount == null)   positionVoteCount = new ArrayList<Integer>(Collections.nCopies(n, 0));
                positionVoteCount.set(pos, positionVoteCount.get(pos) + 1);
                voteMap.put(ch, positionVoteCount);
            }
        }
        
        ArrayList<Character> allTeams = new ArrayList<>(voteMap.keySet());
        Collections.sort(allTeams, (teamA, teamB) -> {
            for(int pos = 0; pos < n; pos++){
                int teamAVotesForPosition = voteMap.get(teamA).get(pos);
                int teamBVotesForPosition = voteMap.get(teamB).get(pos);
                if(teamAVotesForPosition != teamBVotesForPosition)  return (teamBVotesForPosition - teamAVotesForPosition);
            }
            return teamA - teamB;
        });
        
        StringBuilder rankList = new StringBuilder();
        for(Character team : allTeams)  rankList.append(team);
        
        return rankList.toString();
    }
}

