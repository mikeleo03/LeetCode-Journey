class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        int pos = 0; int sentc = 1;

        while (pos < sentence.length()) {
            if (sentence[pos] == searchWord[0]) {
                bool success = true;
                for (int k = 0; k < searchWord.length(); k++) {
                    if (sentence[pos + k] != searchWord[k]) {
                        pos += k; success = false; break;
                    }
                }

                if (success) {
                    return sentc; 
                } else { 
                    while (sentence[pos] != ' ' && pos < sentence.length()) {
                        pos++;
                    }
                }
            } else if (sentence[pos] == ' ') {
                sentc++; pos++;
            } else {
                while (sentence[pos] != ' ' && pos < sentence.length()) {
                    pos++;
                }
            }
        }

        return -1;
    }
};