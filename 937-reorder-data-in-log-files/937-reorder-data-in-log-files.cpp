class Solution {
private:
    static bool myCompare(string a, string b){
        int i = a.find(' ');
        int j = b.find(' ');
        if(!isdigit(a[i + 1]) && !isdigit(b[j + 1])) {
            if (a.substr(i + 1) == b.substr(j + 1)) return a < b;
            return a.substr(i + 1) < b.substr(j + 1);
        } 
        else if (!isdigit(a[i + 1]))
            return true;
        return false;
    }
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        stable_sort(logs.begin(), logs.end(), myCompare);
        return logs;
    }
};