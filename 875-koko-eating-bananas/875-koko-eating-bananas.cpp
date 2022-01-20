class Solution {
private:
    bool can_eat_all_bananas(vector<int>& piles, int h, int k){
        int time_required_to_finish = 0;
        for(int pile : piles){
            time_required_to_finish += ((pile / k) + ((pile % k == 0) ? 0 : 1));
        }
        return (time_required_to_finish <= h);
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1, high = *max_element(piles.begin(), piles.end()), min_eating_speed = high;
        while(low <= high){
            int k = low + (high - low) / 2;
            if(can_eat_all_bananas(piles, h, k)){
                min_eating_speed = min(min_eating_speed, k);
                high = k - 1;
            }
            else{
                low = k + 1;
            }
        }
        return min_eating_speed;
    }
};