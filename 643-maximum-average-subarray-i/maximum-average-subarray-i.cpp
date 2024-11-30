class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int maxSum = INT_MIN;
        int sumWindow = 0;

        for (int i = 0; i < nums.size(); i++) {
            sumWindow += nums[i];
            if (i >= k - 1) {
                maxSum = max(maxSum, sumWindow);
                sumWindow -= nums[i - (k - 1)];
            }
        }

        return (double) maxSum / k;
    }
};