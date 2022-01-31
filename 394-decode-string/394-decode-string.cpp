class Solution {
private:
    string decode_string(string& s, int& i){
        string decoded_string = "";
        while(i < s.length() && s[i] != ']'){
            if(!isdigit(s[i])){
                //cover alphabets
                decoded_string += s[i];
                i++;
            }  
            else{
                //cover numbers
                int num = 0;
                while(i < s.length() && isdigit(s[i])){
                    num = num * 10 + (s[i] - '0');
                    i++;
                }
                i++; // ignore '['
                string encoded_string = decode_string(s, i);
                // i is passed by reference, so it come to the end  of encoded string
                i++; //ignore ']'
                //append the computed decoding of encoded_string num times
                for(int j = 1; j <= num; j++)
                    decoded_string += encoded_string;
            }
        }
        return decoded_string;
    }
public:
    string decodeString(string s) {
        //encoded_string is in form = "alphabets + number[encoded_string] + alphabets + number[encoded_string] + ... + alphabets"
        //can you see recursion?
        int starting_index = 0;
        return decode_string(s, starting_index);
    }
};