class Solution {
public:
    char cyclicIncrement(char c) {
        return (c - 'a' + 1) % 26 + 'a';
    }

    bool canMakeSubsequence(string str1, string str2) {
        int p1 = 0; int p2 = 0;

        while (p1 < str1.length()) {
            if (str1[p1] == str2[p2] || cyclicIncrement(str1[p1]) == str2[p2]) {
                p1++; p2++;
            } else {
                p1++;
            }
        }

        return (p2 == str2.length());
    }
};