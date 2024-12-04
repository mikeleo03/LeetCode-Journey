class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int shortest = 0;

        // satu kali pass, ambil yg paling pendek
        for (int i = 1; i < strs.size(); i++) {
            if (strs[i] < strs[shortest]) shortest = i;
        }

        int curr = 0;
        bool valid = true;
        while (valid && curr < strs[shortest].length()) {
            char currChar = strs[shortest][curr];
            for (int i = 0; i < strs.size(); i++) {
                if (currChar != strs[i][curr]) {
                    valid = false; break;
                }
            }
            if (valid) curr++;
        }

        return strs[shortest].substr(0, curr);
    }
};