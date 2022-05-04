class Solution {
public:
    int maxOperations(vector<int>& num, int k) {
        sort(num.begin(), num.end());
        int ans = 0, i=0, j=num.size() - 1;
        while(i < j){
            if(num[i] + num[j] < k)
                i++;
		    else if(num[i] + num[j] > k)
                j--;
            else{
                ans++;
                i++;
                j--; 
            }
      }
      return ans;
    }
};