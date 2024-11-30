class Solution {
public:
    bool isVowel(char c) {
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
    }

    int maxVowels(string s, int k) {
        int maxVows = INT_MIN; int vows = 0;
        int i = 0; int j = 0;

        while (j < s.length()) {
            if (isVowel(s[j])) vows++;
            if (j - i + 1 < k) {
                j++;
            } else {
                maxVows = max(maxVows, vows);
                if (isVowel(s[i])) vows--;
                i++; j++;
            }
        }

        return max(maxVows, vows);
    }
};