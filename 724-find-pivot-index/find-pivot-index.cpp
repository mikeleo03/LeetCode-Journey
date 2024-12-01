class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int leftSum = 0;

        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
        }

        for (int i = 0; i < nums.size(); i++) {
            sum -= nums[i];
            if (leftSum == sum) {
                return i;
            }
            leftSum += nums[i];
        }

        return -1;
    }
};