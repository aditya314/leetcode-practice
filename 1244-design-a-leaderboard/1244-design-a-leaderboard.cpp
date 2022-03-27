class Leaderboard {
private:
    unordered_map<int, int> scores;
    //using BST instead of min heap to get top k
    //Although the heap is a great data structure for finding the top-K elements from a list without having to actually sort the list, it is not great at find-and-update kind of operations.
    //General rule of thumb with the heap data structure is to use lazy-updates rather than having to traverse and update the entries themselves.
    //We won't get a deterministic performance if we resort to lazy score updates here because we don't know the number of update operations and hence, the size of the heap can continue to grow if we have millions of score updates and no top-K function calls (or proportionally lower).
    set<pair<int, int>> set;  // <score, player id>
public:
    Leaderboard() {
        
    }
    
    void addScore(int playerId, int score) {
        set.erase({scores[playerId], playerId});
        scores[playerId] += score;
        set.insert({scores[playerId], playerId});
    }
    
    int top(int K) {
        int sum = 0;
        int count = 0;
        // Traverse from big to small
        for (auto it = set.rbegin(); it != set.rend() && count < K; it++) {
            count++;
            sum += it->first;
        }
        return sum;
    }
    
    void reset(int playerId) {
        set.erase({scores[playerId], playerId});
        scores[playerId] = 0;
    }    
};
/**
 * Your Leaderboard object will be instantiated and called as such:
 * Leaderboard* obj = new Leaderboard();
 * obj->addScore(playerId,score);
 * int param_2 = obj->top(K);
 * obj->reset(playerId);
 */