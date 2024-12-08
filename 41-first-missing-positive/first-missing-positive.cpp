class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_set<int> map1(nums.begin(), nums.end());

        int num = 1;  int pos = 0;
        while (pos < nums.size()) {
            if (map1.find(num) == map1.end()) {
                return num;
            } else {
                num++;
            }
            pos++;
        }

        return num;
    }
};