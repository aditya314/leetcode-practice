class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int prev_seen_one_index = -1;
        int max_possible = 0, bed_size = flowerbed.size();
        for(int i = 0; i <= bed_size; i++){
                if(i == bed_size || flowerbed[i] == 1){
                    int flower_count = 0;
                    if(prev_seen_one_index == -1 || i == bed_size){
                        flower_count = (i - prev_seen_one_index - 1) / 2;
                        //cout<<i<<prev_seen_one_index<<((i - prev_seen_one_index - 1) / 2);
                    }
                    else{
                        flower_count = (i - prev_seen_one_index - 2) / 2;
                    }
                    //cout<<"For i : "<<i<<" flower count : "<<flower_count<<" prev index : "<<prev_seen_one_index<<endl;
                    max_possible += flower_count;
                    if(i != bed_size)   prev_seen_one_index = i;
                }
        }
        if(prev_seen_one_index == -1)   max_possible = (bed_size + 1) / 2;
        //cout<<max_possible<<" ";
        return (max_possible >= n);
    }
};

// 1 x0s 1
// x ans
// 1 0
// 2 0
// 3 1
// 4 1
// 5 2
// 6 2
// 7 3


