class Solution {
public:
    bool isVowel(char c) {
        // Convert character to lowercase
        c = tolower(c);

        // Check if the character is a vowel
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
    }

    string reverseVowels(string s) {
        int front = 0;
        int back = s.length() - 1;

        while (front < back) {
            if (isVowel(s[front]) && isVowel(s[back])) {
                swap(s[front], s[back]);
                front++; 
                back--;
            }
            if (!isVowel(s[front])) front++;
            if (!isVowel(s[back])) back--;
        }

        return s;
    }
};