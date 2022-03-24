class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int low = 0, high = people.size() - 1;
        int ans = 0;
        while(low <= high){
            //heaviest person can share a boat with the lightest person
            if(people[low] + people[high] <= limit)  low++;
            //the heaviest person sits in their own boat.
            high--;    ans++;
        }
        return ans;
    }
};