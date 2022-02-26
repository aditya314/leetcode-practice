class Solution {
private:
    pair<int, int> find_end_word_and_sentence_size(int start_word_index, vector<string>& words, int max_width){
        int sentence_size = words[start_word_index].size();
        int end_word_index = start_word_index + 1;
        while(end_word_index < words.size() && (sentence_size + 1 + words[end_word_index].size()) <= max_width){
            sentence_size = (sentence_size + 1 + words[end_word_index].size());
            end_word_index++;
        }
        end_word_index--;
        return {end_word_index, sentence_size};
    }
    string get_n_space_string(int n){
        string s(n, ' ');
        return s;
    }
    string justify_words(int start_word_index, int end_word_index, int sentence_size, vector<string>& words, int max_width){
        int extra_spaces = max_width - sentence_size;
        int empty_blocks = end_word_index - start_word_index;
        if(empty_blocks == 0)
            return words[start_word_index] + get_n_space_string(extra_spaces);
        
        int space_per_block = extra_spaces / empty_blocks;
        int space_without_allocated_block = extra_spaces % empty_blocks;
        bool is_last_line = (end_word_index == (words.size() - 1));
        string line = "";
        while(start_word_index < end_word_index){
            line += (words[start_word_index] + " ");
            if(not is_last_line){
                line += get_n_space_string(space_per_block);
                if(space_without_allocated_block > 0){
                    line += " ";
                    space_without_allocated_block--;
                }
            }
            start_word_index++;
        }
        line += words[end_word_index];
        if(is_last_line)
            line += get_n_space_string(extra_spaces);
        return line;
    }
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int n = words.size();
        vector<string> justified_string;
        int start_word_index = 0, size = 0;
        while(start_word_index < n){
            pair<int, int> line_info = find_end_word_and_sentence_size(start_word_index, words, maxWidth);
            int end_word_index = line_info.first;
            int sentence_size = line_info.second;
            justified_string.push_back(justify_words(start_word_index, end_word_index, sentence_size, words, maxWidth));
            start_word_index = end_word_index + 1;
        }
        return justified_string;
    }
};