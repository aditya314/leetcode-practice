class Solution {
public:
    int myAtoi(string str) {
        int sign = 1, num = 0, i = 0;
        while (str[i] == ' ')   i++;
        if (str[i] == '-' || str[i] == '+') {
            sign = 1 - 2 * (str[i++] == '-'); 
        }
        while (str[i] >= '0' && str[i] <= '9') {
            if (num >  INT_MAX / 10 || (num == (INT_MAX / 10) && (str[i] - '0') > (INT_MAX % 10)))
            return (sign == 1) ? INT_MAX : INT_MIN;
            num  = 10 * num + (str[i++] - '0');
        }
        return num * sign;
    }
};