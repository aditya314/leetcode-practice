class Solution {
    public List<String> letterCombinations(String digits) {
        LinkedList<String> answer = new LinkedList<String>();
        if(digits.isEmpty())    return answer;
        answer.add("");
        while(answer.peek().length() != digits.length()){
            String parent = answer.remove();
            String possible_chars = mapping[digits.charAt(parent.length()) - '0'];
            for(char ch : possible_chars.toCharArray()){
                answer.add(parent + ch);
            }
        }
        return answer;
    }
    private String[] mapping = new String[] {"0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
}