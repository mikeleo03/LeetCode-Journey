class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        if (nums.size() == 1) {
            if (nums[0] <= 0) {
                return 1;
            } else if(nums[0] == 1) {
                return 2;
            }
            return 1;
        }
        
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] <= 0) {
                nums[i] = n + 1;
            }
        }

        for (int i = 0; i < n; i++) {
            if (abs(nums[i]) > n) {
                continue;
            } else {
                if (nums[abs(nums[i]) - 1] < 0) {
                    continue;
                } else {
                    nums[abs(nums[i]) - 1] *= -1;
                }
            }
        }

        for (int i = 0; i < n; i++) {
            if (nums[i] >= 0) {
                return i + 1;
            }
        }

        return n+1;
    }
};