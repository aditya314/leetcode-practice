class TrieNode{
public:
    char val;
    bool is_end = false;
    unordered_map<char, TrieNode* > children;
    TrieNode(){}
    TrieNode(char ch) {
        this->val = ch;
    }
};

class Trie {
private:
    TrieNode* root;
public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* temp = root;
        for(char ch : word){
            if(temp->children.find(ch) == temp->children.end()){
                temp->children[ch] = new TrieNode(ch);
            }
            temp = temp->children[ch];
        }
        temp->is_end = true;
    }
    
    bool search(string word) {
        TrieNode* temp = root;
        for(char ch: word){
            if(temp->children.find(ch) == temp->children.end())    return false;
            temp = temp->children[ch];
        }
        return (temp->is_end);
    }
    
    bool startsWith(string prefix) {
        TrieNode* temp = root;
        for(char ch: prefix){
            if(temp->children.find(ch) == temp->children.end())    return false;
            temp = temp->children[ch];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */