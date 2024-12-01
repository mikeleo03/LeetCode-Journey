class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> map1(nums1.begin(), nums1.end());
        unordered_set<int> map2(nums2.begin(), nums2.end());

        for (int num : nums2) {
            if (map1.find(num) != map1.end()) {
                map1.erase(num); 
                map2.erase(num);
            }
        }

        return { vector<int>(map1.begin(), map1.end()), vector<int>(map2.begin(), map2.end()) };
    }
};