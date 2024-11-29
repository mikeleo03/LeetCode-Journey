class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string word = "";
        int len1 = word1.length();
        int len2 = word2.length();
        
        // ambil paling panjang
        int min = len1 > len2 ? len2 : len1;

        for (int i = 0; i < min; i++) {
            word += word1[i]; len1--;
            word += word2[i]; len2--;
        }

        if (len1 > 0) {
            while (len1 > 0) {
                word += word1[word1.length() - len1];
                len1--;
            }
        } else if (len2 > 0) {
            while (len2 > 0) {
                word += word2[word2.length() - len2];
                len2--;
            }
        }

        return word;
    }
};