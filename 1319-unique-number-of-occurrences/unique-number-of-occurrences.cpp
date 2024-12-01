class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> map;

        for (int i = 0; i < arr.size(); i++) {
            if (map.find(arr[i]) != map.end()) {
                map[arr[i]]++;
            } else {
                map[arr[i]] = 1;
            }
        }

        // iterate the map
        for (auto it = map.begin(); it != map.end(); it++) {
            for (auto it2 = it; it2 != map.end(); it2++) {
                if (it != it2 && it->second == it2->second) return false;
            }
        }

        return true;
    }
};