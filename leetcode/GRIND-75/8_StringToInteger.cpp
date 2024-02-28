class Solution {
#define ll long
public:
    int myAtoi(string s) {
        int i = 0;
        int sign = 1;
        ll base = 0;
        while(s[i] == ' '){
            i++;
        }
        if(s[i] == '-' || s[i] == '+'){
            sign = 1 - 2 * (s[i++] == '-'); // sign of number
        }
        while(s[i] >= '0' && s[i] <= '9'){
            base = base * 10 + (s[i++] - '0'); // calculating the base value, prefix zeroes handled
            if(base > INT_MAX){
                if(sign == 1)
                    return INT_MAX;
                else 
                    return INT_MIN;
            }
        }
        return (int) sign * base;
    }
};