class Solution {
private:
    priority_queue<int> pq;
    void pq_push(int x, int k) {
        /* Limit size of max heap (greatest number first) to k only, so that top will always have result */
        pq.push(x); 
        if (pq.size()>k) {
            //larger divisor will pop out, only smaller ones in heap
           pq.pop(); 
        }
    }
public:
    int kthFactor(int n, int k) {
        int sqrtN = (int)sqrt(n);
        for (int x = 1; x < sqrtN + 1; ++x) {
            if (n % x == 0) {
                pq_push(x, k);
                if (x != n / x) { 
                    /* If perfect square, then duplicate number will be added, hence prevent adding duplicate by this check: If n= x*x, then x should be added only once */
                    pq_push(n / x, k);    
                }    
            }    
        }
                
        return k == pq.size() ? pq.top(): -1;
    }
};