class Solution {
public:
    string removeStars(string s) {
        int index = 0;
        for (char ch : s) {
            ch == '*' ? index-- : s[index++] = ch;
        }
        
        return s.substr(0,index);
    }
};