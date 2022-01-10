class Solution {
public:
    string addBinary(string a, string b) {
        if(a.size() < b.size())     return addBinary(b, a);
        int i = a.size() - 1, j = b.size() - 1, carry = 0;
        string res = "";
        while(i >= 0 || j >= 0 || carry > 0){
            int digit_sum = ((i >= 0) ? (a[i] - '0') : 0) 
                            + ((j >= 0) ? (b[j] - '0') : 0) + carry;
            if(digit_sum <= 1){
                carry = 0;
                res = res + (char)(digit_sum + '0');
            }
            else if(digit_sum == 2){
                carry = 1;
                res = res + '0';
            }
            else if(digit_sum == 3){
                carry = 1;
                res = res + '1';
            }
            i--;    j--;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};