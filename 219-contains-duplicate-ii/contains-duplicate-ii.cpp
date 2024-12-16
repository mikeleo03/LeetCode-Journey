class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        int front = 0; int back = 0;
        map[nums[back]]++;

        while (back < nums.size()) {
            if (back - front > k) {
                map[nums[front]]--;
                front++;
            }

            // Check count
            if (map.find(nums[back]) != map.end()) {
                // cout << back << " " << nums[back] << " " << map[nums[back]] << endl;
                if (map[nums[back]] == 2) return true;
            }

            back++;
            if (back < nums.size()) map[nums[back]]++;
        }

        return false;
    }
};