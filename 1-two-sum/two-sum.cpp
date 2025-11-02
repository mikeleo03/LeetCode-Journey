class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> m1;
        for (int i = 0; i < nums.size(); i++) {
            int remaining = target - nums[i];
            auto it = m1.find(remaining);
            if (it != m1.end()) {
                return vector<int>{it->second, i};
            }
            m1[nums[i]] = i;
        }
        return vector<int>{-1, -1};
    }
};