class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int prev_seen_one_index = -1;
        int max_possible = 0, bed_size = flowerbed.size();
        for(int i = 0; i < bed_size; i++){
                if(flowerbed[i] == 1){
                    int flower_count = ((prev_seen_one_index == -1) ? (i - prev_seen_one_index - 1) : (i - prev_seen_one_index - 2) ) / 2;
                    max_possible += flower_count;
                    prev_seen_one_index = i;
                }
        }
        if(prev_seen_one_index == -1)   max_possible = (bed_size + 1) / 2;
        else    max_possible += (bed_size - prev_seen_one_index - 1) / 2;
        return (max_possible >= n);
    }
};
//Test cases:
// y0s 1
// 1 y0s
// y0s
// 1 x0s 1
// x ans
// 1 0
// 2 0
// 3 1
// 4 1
// 5 2
// 6 2
// 7 3


