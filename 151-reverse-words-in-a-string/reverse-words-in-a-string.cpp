class Solution {
public:
    string reverseWords(string s) {
        vector<string> result;

        int pos = 0;
        string currWord = "";
        while (pos < s.size()) {
            if (s[pos] == ' ') {
                if (currWord != "") {
                    result.push_back(currWord);
                    currWord = "";
                }
            } else {
                currWord += s[pos];
            }

            pos++;
        }

        if (s[s.size() - 1] != ' ') result.push_back(currWord);

        // akhirnya kita dapet array of string
        string stringres = "";
        for (int i = result.size() - 1; i >= 0; i--) {
            stringres += result[i];
            if (i != 0) stringres += ' ';
        }

        // printing them to stringres
        return stringres;
    }
};