class Solution {
public:
    int titleToNumber(string columnTitle) {
        int result = 0; int count = 0;
        for (int i = columnTitle.size() - 1; i >= 0; i--) {
            char ch = columnTitle[i];
            int ascii_value = ch;
            result += (ascii_value - 64) * pow(26, count);
            count++;
        }

        return result;
    }
};