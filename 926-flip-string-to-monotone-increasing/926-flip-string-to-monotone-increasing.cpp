class Solution {
    // if c is 1, then it will not inpact the minFlips
    // if c is 0, then 2 options we can do to make it mono incr
    // 1. keep it as 0, and flip all the preceeding 1 to 0, need to know the count of ones so far
    // 2. flip it to 1, will not need to do anything
public:
    int minFlipsMonoIncr(string s) {
        int counter_one = 0, counter_flip = 0;
        for (char ch : s) {
            if (ch == '1') counter_one++;
            else{
                counter_flip++;
                counter_flip = min(counter_flip, counter_one);
            }
        }
        return counter_flip;
    }
};