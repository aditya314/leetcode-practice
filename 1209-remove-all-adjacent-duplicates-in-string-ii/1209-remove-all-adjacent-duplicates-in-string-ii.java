class Solution {
    class Adjacent{
        char ch;
        int freq;
        public Adjacent(char ch, int freq){
            this.ch = ch;
            this.freq = freq;
        }
    }
    //if using LinkedList then can use the addLast() and removeLast() methods, in which case there isnt any need to reverse the string. But a stack implemented as a ArrayDeque is faster than a LinkedList.
    //https://stackoverflow.com/questions/6163166/why-is-arraydeque-better-than-linkedlist#:~:text=ArrayDeque%20and%20LinkedList%20are%20implementing,LinkedList%20but%20not%20in%20ArrayDeque
    public String removeDuplicates(String s, int k) {
        ArrayDeque<Adjacent> st = new ArrayDeque<>(s.length());
        for (char c : s.toCharArray()) {
            if(!st.isEmpty() && st.peekLast().ch == c)
                st.peekLast().freq++;
            else
                st.addLast(new Adjacent(c, 1));
            if(st.peekLast().freq == k)
                st.removeLast();
        }
        StringBuilder sb = new StringBuilder();
        for (Adjacent adj : st) {
            sb.append(String.valueOf(adj.ch).repeat(adj.freq));
        }
        return sb.toString();
    }
}