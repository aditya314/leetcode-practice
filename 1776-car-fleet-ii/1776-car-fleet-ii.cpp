class Solution {
public:
    vector<double> getCollisionTimes(vector<vector<int>>& cars) {
        int n = cars.size();
        vector<double> res(n, -1.0);
        stack<int> s;
        for (int i = n - 1; i >= 0; --i) {
			// kick out all cars with faster speed.
            while (!s.empty() && cars[s.top()][1] >= cars[i][1]) 
                s.pop();
            double time = -1.0;
            while (!s.empty()) {
                time = (cars[s.top()][0] - cars[i][0]) 
                            / (double) (cars[i][1] - cars[s.top()][1]);
                if (res[s.top()] == -1 || time <= res[s.top()]) break;
				// kick out all cars already gone.
                s.pop();
            }
            res[i] = time;
            s.push(i);
        }
        return res;
    }
};

//[[1,2],[2,1],[4,3],[7,2]]
// (2 - 1) / (2 - 1), (4 - 2) / (1 - 3), (7 - 4) / ( 3 - 2)