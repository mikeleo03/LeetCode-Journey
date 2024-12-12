class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> map1;

        for (char c : magazine) {
            map1[c]++;
        }

        for (char c : ransomNote) {
            if (map1.find(c) != map1.end()) {
                if (map1[c] > 0) {
                    map1[c]--;
                } else {
                    return false;
                }
            } else {
                return false;
            }
        }

        return true;
    }
};