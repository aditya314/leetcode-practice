class Solution {
    //Time complexity : O(n*(cols/lenAverage)) + O(rows), where n is the length of sentence array, lenAverage is the average length of the words in the input 
    //space O(n)
public:
    int wordsTyping(vector<string>& sentence, int rows, int cols) {
        int n = sentence.size();
        vector<int> next_word(n);
        vector<int> repeatition(n);
        for(int i = 0; i < n; i++){
            int next_word_index = i, repetition_count = 0, col_index = 0;
            while(col_index + sentence[next_word_index].length() <= cols){ //can ignore space  
                col_index += (sentence[next_word_index].length() + 1); //include space too
                next_word_index++;
                if(next_word_index == n){
                    repetition_count++;
                    next_word_index = 0;
                }
            }
            next_word[i] = next_word_index;
            repeatition[i] = repetition_count;
        }
        int answer = 0, curr_word_index = 0;
        for(int i = 0; i < rows; i++){
            answer += repeatition[curr_word_index];
            curr_word_index = next_word[curr_word_index];
        }
        return answer;
    }
};