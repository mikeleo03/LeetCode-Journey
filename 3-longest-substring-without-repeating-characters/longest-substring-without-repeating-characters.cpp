class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // State
        int front = 0; int back = 0;
        set<char> charset;
        int sizeMax = 1;

        if (s.size() == 0) return 0;

        while (front < s.size() && back < s.size()) {
            // Is in the set
            if (!charset.count(s[front])) {
                charset.insert(s[front]);
                sizeMax = max(sizeMax, front - back + 1);
            } else {
                while (s[back] != s[front]) {
                    charset.erase(s[back]);
                    back++;
                }
                back++;
            }
            front++;
        }


        // Return
        return sizeMax;
    }
};