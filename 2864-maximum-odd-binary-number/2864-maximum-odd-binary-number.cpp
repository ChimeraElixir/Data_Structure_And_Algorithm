class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int bits = s.length();
        string obn(bits, '0'); 
        int count = 0;
        for (int i = 0; i < bits; i++) {
            if (s[i] == '1') {
                count++;
            }
        }

        if (count == 0) return "0"; 
        obn[bits - 1] = '1';
        count--;

        int i = 0; 
        while (count) {
            obn[i] = '1';
            count--;
            i++;
        }

        return obn;
    }
};
