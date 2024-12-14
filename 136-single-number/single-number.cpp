class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_set<int> map;

        for (int num : nums) {
            if (map.find(num) != map.end()) {
                map.erase(num);
            } else {
                map.insert(num);
            }
        }

        for (auto it = map.begin(); it != map.end(); it++) {
            return *it;
        }

        return -1;
    }
};