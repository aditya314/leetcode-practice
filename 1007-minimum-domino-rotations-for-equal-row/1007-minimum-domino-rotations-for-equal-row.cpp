class Solution {
private:
    int get_rotations(int target, vector<int>& tops, vector<int>& bottoms){
        int rotation = 0;
        for(int i = 0; i < tops.size(); i++){
            if(tops[i] != target){
                if(bottoms[i] != target)
                    return INT_MAX;
                rotation++;
            }
        }
        return rotation;
    }
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int min_rotation = 
            min(get_rotations(tops[0], tops, bottoms),
                min(get_rotations(bottoms[0], tops, bottoms),
                    min(get_rotations(tops[0], bottoms, tops),
                        get_rotations(bottoms[0], bottoms, tops))));
        return (min_rotation != INT_MAX) ? min_rotation : -1;
    }
};