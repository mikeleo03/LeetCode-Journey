class Solution {
public:
    bool closeStrings(string word1, string word2) {
        unordered_map<char, int> map1;
        unordered_map<char, int> map2;
        unordered_map<int,vector<char>> count1;
        unordered_map<int,vector<char>> count2;

        // initial size check
        if (word1.length() != word2.length()) return false;

        for (int i = 0; i < word1.size(); i++) {
            map1[word1[i]]++;
        }

        for (int i = 0; i < word2.size(); i++) {
            map2[word2[i]]++;
        }

        // checks
        bool valuesMatch = true;

        // Map size check
        if (map1.size() != map2.size()) return false;

        // Operator 1
        for (auto it : map1) {
            if (map2.find(it.first) == map2.end()) return false;
            if (it.second != map2[it.first]) { valuesMatch = false; }
        }

        if (valuesMatch) { return true; } else { valuesMatch = true; }

        // Operator 2
        for (auto it : map1) {
            count1[it.second].push_back(it.first);
        }
        for (auto it : map2) {
            count2[it.second].push_back(it.first);
        }

        // Iterate through the first map
        for (auto it : count1) {
            if (count2.find(it.first) == count2.end()) {
                return false;
            } else if (it.second.size() != count2[it.first].size()) { 
                return false;
            }
        }

        return true;
    }
};