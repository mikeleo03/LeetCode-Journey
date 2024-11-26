class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums[0];
        int c = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (c == 0) n = nums[i];
            nums[i] == n ? c++ : c--;
        }
        return n;
    }
};