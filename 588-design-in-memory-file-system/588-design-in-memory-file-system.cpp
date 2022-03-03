class Directory{
public:
    string content;
    unordered_map<string, Directory*> sub_directories;
    bool is_file;
    Directory(){
        this->is_file = false;
    }
};
class FileSystem {
private:
    Directory* root_directory;
    vector<string> split(string &path, char d) {
        vector<string> ans;
        int i = 1, j = 1;
        while (j <= path.length()) {
            if (i != j && (j == path.length() || path[j] == d)) {
                ans.push_back(path.substr(i, j - i));
                i = j + 1;
            }
            ++j;
        }
        return ans;
    }
public:
    FileSystem() {
        this->root_directory = new Directory();
    }
    
    vector<string> ls(string path) {
        vector<string> directory_path = split(path, '/');
        Directory* curr_dir = root_directory;
        for(string& dir : directory_path)
            curr_dir = curr_dir -> sub_directories[dir];
        
        if(curr_dir->is_file)
            return {directory_path.back()};
        
        vector<string> ls_dir;
        for(pair<string, Directory*> sub_dir: curr_dir -> sub_directories)
            ls_dir.push_back(sub_dir.first);
        sort(ls_dir.begin(), ls_dir.end());
        
        return ls_dir;
    }
    
    void mkdir(string path) {
        vector<string> directory_path = split(path, '/');
        Directory* curr_dir = root_directory;
        for(string& dir : directory_path){
            if (curr_dir->sub_directories.find(dir) == curr_dir->sub_directories.end())
                curr_dir->sub_directories[dir] = new Directory();
            curr_dir = curr_dir -> sub_directories[dir];
        }
    }
    
    void addContentToFile(string filePath, string content) {
        vector<string> directory_path = split(filePath, '/');
        Directory* curr_dir = root_directory;
        for(string& dir : directory_path){
            if (curr_dir->sub_directories.find(dir) == curr_dir->sub_directories.end())
                curr_dir->sub_directories[dir] = new Directory();
            curr_dir = curr_dir -> sub_directories[dir];
        }
        curr_dir -> is_file = true;
        curr_dir -> content += content;
    }
    
    string readContentFromFile(string filePath) {
        vector<string> directory_path = split(filePath, '/');
        Directory* curr_dir = root_directory;
        for(string& dir : directory_path)
            curr_dir = curr_dir -> sub_directories[dir];
        return curr_dir -> content;
    }
};

/**
 * Your FileSystem object will be instantiated and called as such:
 * FileSystem* obj = new FileSystem();
 * vector<string> param_1 = obj->ls(path);
 * obj->mkdir(path);
 * obj->addContentToFile(filePath,content);
 * string param_4 = obj->readContentFromFile(filePath);
 */