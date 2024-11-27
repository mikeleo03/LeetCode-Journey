class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res(nums.size(), 1);
        
        // Calculate prefix
        int prefix = 1;
        for (int i = 0; i < nums.size() - 1; i++) {
            prefix *= nums[i];
            res[i + 1] *= prefix;
        }

        // Calculate suffix
        int suffix = 1;
        for (int i = nums.size() - 1; i > 0; i--) {
            suffix *= nums[i];
            res[i - 1] *= suffix;
        }

        return res;
    }
};