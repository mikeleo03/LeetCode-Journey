class Solution {
public:
    bool isVowel(char c) {
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
    }

    int maxVowels(string s, int k) {
        int mv = INT_MIN; int v = 0; 
        int i = 0; int j = 0;

        while (j < s.length()) {
            if (isVowel(s[j])) v++;
            if (j - i + 1 < k) { j++;} 
            else {
                mv = max(mv, v);
                if (isVowel(s[i])) v--;
                i++; j++;
            }
        }

        return max(mv, v);
    }
};