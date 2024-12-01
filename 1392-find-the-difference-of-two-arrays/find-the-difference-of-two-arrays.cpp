class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> map1;
        unordered_map<int, int> map2;

        for (int num : nums1) {
            if (map1.find(num) != map1.end()) {
                map1[num]++;
            } else {
                map1[num] = 1;
            }
        }

        for (int num : nums2) {
            if (map2.find(num) == map2.end()) {
                if (map1.find(num) != map1.end()) {
                    map1[num] = 0;
                } else {
                    map2[num] = 1;
                }
            } else {
                map2[num]++;
            }
        }

        vector<vector<int>> result(2);
        for (auto it = map1.begin(); it != map1.end(); it++) {
            if (it->second > 0) result[0].push_back(it->first);
        }

        for (auto it = map2.begin(); it != map2.end(); it++) {
            if (it->second > 0) result[1].push_back(it->first);
        }

        return result;
    }
};