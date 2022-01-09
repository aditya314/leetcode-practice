class Solution {
public:
    bool isRobotBounded(string instructions) {
        int direction_index = 0; //NORTH, EAST, SOUTH, WEST
        pair<int, int> coordinate = {0,0};
        for(char ch :  instructions){
            if(ch == 'G'){
                if(direction_index == 0)        coordinate.second++;
                else if(direction_index == 1)   coordinate.first++;
                else if(direction_index == 2)   coordinate.second--;
                else if(direction_index == 3)   coordinate.first--;
            }
            else if(ch == 'L')  direction_index = (direction_index - 1 + 4) % 4;
            else if(ch == 'R')  direction_index = (direction_index + 1) % 4;
        }
        return (coordinate.first == 0 && coordinate.second == 0) || (direction_index != 0);
    }
};