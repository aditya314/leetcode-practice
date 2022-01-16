class Solution {
    public boolean lemonadeChange(int[] bills) {
        HashMap<Integer, Integer> noteCount = new HashMap<Integer, Integer>();
        noteCount.put(5, 0);
        noteCount.put(10, 0);
        noteCount.put(20, 0);
        for(int bill : bills){
            if(bill == 10){
                if(noteCount.get(5) <= 0) return false;
                noteCount.put(5, noteCount.get(5) - 1);   
            }
            else if(bill == 20){
                if(noteCount.get(5) <= 0) return false;
                if(noteCount.get(10) <= 0){
                    if(noteCount.get(5) <= 2)    return false;
                    noteCount.put(5, noteCount.get(5) - 3);
                }
                else{
                    noteCount.put(5, noteCount.get(5) - 1);
                    noteCount.put(10, noteCount.get(10) - 1);
                }
            }
            noteCount.put(bill, noteCount.get(bill) + 1);
        }
        return true;
    }
}