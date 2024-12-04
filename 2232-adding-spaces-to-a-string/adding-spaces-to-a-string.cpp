class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        int posSpace = 0;
        int posString = 0;
        string res;

        while (posString < s.length()) {
            if (posSpace < spaces.size()) {
                if (posString == spaces[posSpace] && posSpace < spaces.size()) {
                    res += " "; posSpace++; continue;
                }
            }
            
            res += s[posString]; posString++;
        }

        return res;
    }
};