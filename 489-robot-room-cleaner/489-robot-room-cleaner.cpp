/**
 * // This is the robot's control interface.
 * // You should not implement it, or speculate about its implementation
 * class Robot {
 *   public:
 *     // Returns true if the cell in front is open and robot moves into the cell.
 *     // Returns false if the cell in front is blocked and robot stays in the current cell.
 *     bool move();
 *
 *     // Robot will stay in the same cell after calling turnLeft/turnRight.
 *     // Each turn will be 90 degrees.
 *     void turnLeft();
 *     void turnRight();
 *
 *     // Clean the current cell.
 *     void clean();
 * };
 */

class Solution {
private:
    enum Direction{
        UP, RIGHT, DOWN, LEFT
    };
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    unordered_set<string> visited;
    string get_compressed_point(int x, int y){
        return to_string(x) + " " + to_string(y);
    }
    void go_back_one_step(Robot& robot){
        robot.turnRight();
        robot.turnRight();
        //turn back 180 degrees
        robot.move();
        robot.turnLeft();
        robot.turnLeft();
        //turn back 180 degrees
    }
    void backtrack(Robot& robot, int x, int y, Direction dir){
        robot.clean();
        for(int k = 0; k < 4; k++){
            int new_dir = (dir + k) % 4;
            int new_x = x + dx[new_dir];
            int new_y = y + dy[new_dir];
            string compressed_point = get_compressed_point(new_x, new_y);
            if((visited.find(compressed_point) == visited.end()) && robot.move()){
                visited.insert(compressed_point);
                backtrack(robot, new_x, new_y, (Direction) new_dir);
                go_back_one_step(robot);
            }
            robot.turnRight();
        }
    }
public:
    void cleanRoom(Robot& robot) {
        visited.insert(get_compressed_point(0, 0));
        backtrack(robot, 0, 0, UP);
    }
};