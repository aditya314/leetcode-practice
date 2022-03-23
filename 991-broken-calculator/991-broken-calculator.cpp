class Solution {
public:
    int brokenCalc(int startValue, int target) {
        int answer = 0;
        while (target > startValue) {
            target = (target & 1) ? (target + 1) : (target >> 1);
            answer++;
        }
        answer += (startValue - target);
        return answer;
    }
};