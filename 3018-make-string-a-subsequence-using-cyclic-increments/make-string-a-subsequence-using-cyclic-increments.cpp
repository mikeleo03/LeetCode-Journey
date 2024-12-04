class Solution {
public:
    char cyclicIncrement(char c) {
        return (c - 'a' + 1) % 26 + 'a';
    }

    bool canMakeSubsequence(string str1, string str2) {
        int m = str1.size(), n = str2.size(); int p2 = 0;
        if (m < n) return false;

        for (int p1 = 0; p1 < m && p2 < n; p1++) {
            if (str1[p1] == str2[p2] || 
                str1[p1] + 1 == str2[p2] ||
                str1[p1] - 25 == str2[p2]) p2++;
        }

        return p2 == n;
    }
};