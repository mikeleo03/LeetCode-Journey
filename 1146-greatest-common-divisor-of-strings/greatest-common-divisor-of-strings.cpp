class Solution {
public:
    int gcd(int a, int b) {
        if (a == 0) return b;
        return gcd(b % a, a);
    }

    string gcdOfStrings(string str1, string str2) {
        int len1 = str1.length(); int len2 = str2.length();
        // int length = len1 > len2 ? len2 : len1;
        int gcdLen = gcd(len1, len2);
        string gcdStr = str2.substr(0, gcdLen);

        // Validate to str1
        int valid = true;

        int pos1 = 0;
        while (pos1 < len1) {
            for (int i = 0; i < gcdLen; i++) {
                if (str1[pos1 + i] != gcdStr[i]) {valid = false; break;}
            }
            pos1 += gcdLen;
        }

        int pos2 = 0;
        while (pos2 < len2) {
            for (int i = 0; i < gcdLen; i++) {
                if (str2[pos2 + i] != gcdStr[i]) {valid = false; break;}
            }
            pos2 += gcdLen;
        }

        return valid ? gcdStr : "";
    }
};