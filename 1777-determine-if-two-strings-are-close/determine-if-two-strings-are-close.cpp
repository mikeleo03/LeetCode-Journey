class Solution {
public:
    bool closeStrings(string word1, string word2) {
        map<char, int> map1;
        map<char, int> map2;
        map<int, int> count1;
        map<int, int> count2;

        // initial size check
        if (word1.length() != word2.length()) return false;

        for (int i = 0; i < word1.size(); i++) {
            if (map1.find(word1[i]) != map1.end()) {
                count1[map1[word1[i]]]--;
                map1[word1[i]]++;
                count1[map1[word1[i]]]++;
            } else {
                map1[word1[i]] = 1;
                count1[1]++;
            }
        }

        for (int i = 0; i < word2.size(); i++) {
            if (map2.find(word2[i]) != map2.end()) {
                count2[map2[word2[i]]]--;
                map2[word2[i]]++;
                count2[map2[word2[i]]]++;
            } else {
                map2[word2[i]] = 1;
                count2[1]++;
            }
        }

        // checks
        bool valuesMatch = true;

        // Map size check
        if (map1.size() != map2.size()) return false;

        // Operator 1
        // Iterate through the first map
        for (const auto& [key, value] : map1) {
            // Check if the key exists in the second map
            if (map2.count(key)) {
                // Compare values for shared keys
                if (map2.at(key) != value) {
                    valuesMatch = false;
                }
            } else {
                // Key is in map1 but not in map2
                return false;
            }
        }

        // Check if all keys in map2 are also in map1
        for (const auto& [key, value] : map2) {
            if (map1.count(key) == 0) {
                valuesMatch = false;
                break;
            }
        }

        if (valuesMatch) { return valuesMatch; } else { valuesMatch = true; }

        // Operator 2
        // Iterate through the first map
        for (const auto& [key, value] : count1) {
            // Check if the key exists in the second map
            if (count2.count(key)) {
                // Compare values for shared keys
                if (count2.at(key) != value) {
                    valuesMatch = false;
                }
            } else {
                // Key is in map1 but not in map2
                return false;
            }
        }

        // Check if all keys in map2 are also in map1
        for (const auto& [key, value] : count2) {
            if (count1.count(key) == 0) {
                valuesMatch = false;
                break;
            }
        }

        return valuesMatch;
    }
};