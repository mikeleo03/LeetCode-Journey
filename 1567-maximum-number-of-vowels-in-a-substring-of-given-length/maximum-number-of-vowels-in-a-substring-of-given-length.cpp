class Solution {
public:
    bool isVowel(char c) {
        if (!isalpha(c)) return false; // Check if it's a letter
        c = tolower(c);
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
    }

    int maxVowels(string s, int k) {
        int maxVows = 0; int vows = 0;

        for (int i = 0; i < s.size(); i++) {
            if (isVowel(s[i])) vows++;
            if (i > k - 1 && isVowel(s[i - k])) vows--;
            maxVows = max(maxVows, vows);
        }

        return maxVows;
    }
};