class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int count = 1;
        int result = 0;
        for(int i = 0; i < flowerbed.size(); i++) {
            if(flowerbed[i] == 0) {
                count++;
            }
            else {
                result += (count - 1) / 2;
                count = 0;
            }
        }
        if(count != 0) result += count/2;
        return (result >= n);
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


