class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        int min_deviation = INT_MAX, min_number = INT_MAX;
        //max heap
        priority_queue<int> pq;
        for (int n : nums) {
            //only odd numbers can be maximised
            if(n % 2 == 1)     n = n << 1;
            pq.push(n);
            min_number = min(min_number, n); 
        }
        //there are only two ways to decrease deviation: decrease maximum, or increase minimum.
        // If we have increased all numbers to their maximum, then we can not increase minimum. If we want smaller deviation, we can only decrease maximum.
        while (!pq.empty()) {
            int current_max = pq.top();
            pq.pop();
            min_deviation = min(min_deviation, current_max - min_number);
            if(current_max % 2 == 0){
                current_max = current_max >> 1;
                min_number = min(min_number, current_max);
                pq.push(current_max);
            }
            else // odd numbers cannot be minimised
                break;
        }
        return min_deviation;
    }
};