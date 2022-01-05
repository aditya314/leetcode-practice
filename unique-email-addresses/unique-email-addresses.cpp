class Solution {
private:
    string get_forwarded_local_name(string local_name){
        string s = "";
        for(char ch : local_name){
            if(ch == '+')   break;
            if(ch == '.')  continue;
            s += ch;
        }
        return s;
    }
    string get_processed_email(string email){
        int split_index = email.find('@');
        string local_name = email.substr(0, split_index);
        string remaining_part = email.substr(split_index);
        return get_forwarded_local_name(local_name) + remaining_part;
    }
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> email_set;
        int unique_counts = 0;
        for(string email : emails){
            string processed_email = get_processed_email(email);
            //cout<<"Email is "<<email<<" Processed to -> "<<processed_email<<endl;
            if(email_set.find(processed_email) == email_set.end()){
                unique_counts++;
                email_set.insert(processed_email); 
            }      
        }
        return unique_counts;
    }
};