class Solution {
private:
    unordered_map<string, string> short_to_long, long_to_short;
    const string charset = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    const int code_length = 8;
    string generate_random_short_url(){
        string code = "";
        for(int i = 0; i < code_length; i++)
            code += charset[rand() % 62];
        return "http://tinyurl.com/" + code;
    }
public:

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        if(long_to_short.find(longUrl) != long_to_short.end())
            return long_to_short[longUrl];
        
        string short_url = generate_random_short_url();
        while(short_to_long.find(short_url) != short_to_long.end())
            short_url = generate_random_short_url();
        
        short_to_long[short_url] = longUrl;
        long_to_short[longUrl] = short_url;
        
        return short_url;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return short_to_long[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));