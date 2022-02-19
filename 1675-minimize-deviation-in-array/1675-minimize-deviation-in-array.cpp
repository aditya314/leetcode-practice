class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        int res = INT_MAX, min_number = INT_MAX;
        priority_queue<int> pq;
        for (int n : nums) {
            if(n % 2 == 1)     n = n << 1;
            pq.push(n);
            min_number = min(min_number, n); 
        }
        while (pq.top() % 2 == 0) {
            res = min(res, pq.top() - min_number);
            min_number = min(min_number, pq.top() / 2);
            pq.push(pq.top() / 2);
            pq.pop();
        }
        res = min(res, pq.top() - min_number);
        return res;
    }
};