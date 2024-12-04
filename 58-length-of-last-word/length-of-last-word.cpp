class Solution {
public:
    int lengthOfLastWord(string s) {
        int num = 0;
        int pos = s.length() - 1;

        // find first letter
        while (s[pos] == ' ') pos--;

        // fins another space
        while (s[pos] != ' ' && pos > 0) { num++; pos--; }

        return pos == 0 && s[pos] != ' ' ? num + 1 : num;
    }
};