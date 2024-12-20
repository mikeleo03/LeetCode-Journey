class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> set;
        unordered_set<int> result_set;
        vector<int> res;

        for (int num : nums1) {
            set.insert(num);
        }

        for (int num : nums2) {
            if (set.find(num) != set.end()) {
                result_set.insert(num);
            }
        }

        for (auto i : result_set) {
            res.push_back(i);
        }

        return res;
    }
};