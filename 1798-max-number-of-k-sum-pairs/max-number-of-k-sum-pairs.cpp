class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        int counter = 0;

        for (int i = 0; i < nums.size(); i++) {
            int res = k - nums[i];
            if (map.find(res) != map.end()) {
                counter++;
                if (map[res] == 1) map.erase(res);
                else map[res]--;
            } else {
                map[nums[i]]++;
            }
        }

        return counter;
    }
};