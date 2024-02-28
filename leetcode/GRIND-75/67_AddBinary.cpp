class Solution {
public:
    string addBinary(string a, string b) {
        int p = a.length();
        int q = b.length();
        int i=0;
        int carry = 0;
        string res = "";
        while(i < p || i < q || carry != 0){
            int x=0, y=0;
            if(i < p && a[p-i-1] == '1')
                x = 1;
            if(i < q && b[q-i-1] == '1')
                y = 1;
            res = to_string((x+y+carry)%2) + res;
            carry = (x+y+carry)/2;
            i++;
        }
        return res;
    }
};