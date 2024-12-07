class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int minimum = INT_MAX; int sign = 1;

        // Sort the nums array
        sort(nums.begin(), nums.end());

        for (int small = 0; small < nums.size(); small++) {
            int mid = small + 1; 
            int large = nums.size() - 1;
            
            // calc the current sum
            while (mid < large) {
                int currentSum = nums[small] + nums[mid] + nums[large];
                currentSum < target ? mid++ : large--;
                // calc the minimum gap
                if (minimum > abs(currentSum - target)) {
                    minimum = abs(currentSum - target);
                    currentSum > target ? sign = 1 : sign = -1;
                }
            }
        }

        return target + sign * minimum;
    }
};