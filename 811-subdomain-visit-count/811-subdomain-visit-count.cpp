class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        unordered_map<string, int> count_pair_subdomain;
        for(string cp_domain : cpdomains){
            stringstream cp_domain_stream(cp_domain);
            int count;      cp_domain_stream>>count;
            string domain;  cp_domain_stream>>domain;
            count_pair_subdomain[domain] += count;
            for(int i = 0 ; i < domain.length(); i++){
                if(domain[i] == '.')
                    count_pair_subdomain[domain.substr(i + 1)] += count;
            }
        }
        vector<string> counted_pair_domains;
        for(pair<string, int> count_pair : count_pair_subdomain)
            counted_pair_domains.push_back(to_string(count_pair.second) + " " + count_pair.first);
        return counted_pair_domains;
    }
};