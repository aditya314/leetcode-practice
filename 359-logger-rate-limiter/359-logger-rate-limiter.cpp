class Logger {
private:
    const int time_limit = 10;
    unordered_map<string, int> message_logs;
public:
    Logger() {
        
    }
    
    bool shouldPrintMessage(int timestamp, string message) {
        if(message_logs.find(message) == message_logs.end()){
            message_logs[message] = timestamp;
            return true;
        }
        if(timestamp - message_logs[message] >= time_limit){
            message_logs[message] = timestamp;
            return true;
        }
        return false;
    }
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */