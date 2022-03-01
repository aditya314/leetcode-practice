class Solution {
    //transition function of pop count P(x):
    //P(x)=P(x/2)+(xmod2)
public:
    vector<int> countBits(int n) {
        vector<int> answer(n + 1, 0);
        for(int i = 0; i <= n; i++)
            answer[i] = answer[(i / 2)] + (i % 2);
        return answer;
    }
};