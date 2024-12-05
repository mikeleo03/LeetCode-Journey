class Solution {
public:
    int strStr(string haystack, string needle) {
        int pos = 0;
        bool found = false;

        while (pos < haystack.length()) {
            cout << pos << endl;
            int gap = 1;
            for (int i = 0; i < needle.length(); i++) {
                if (haystack[pos + i] != needle[i]) {
                    break;
                } else {
                    gap++;
                }
            }
            
            if (gap == needle.length() + 1) {
                return pos;
            } else {
                pos++;
            }
        }

        return -1;
    }
};