class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        // State
        int front = 0; int back = 0;
        int sum = nums[front]; 
        int minSize = INT_MAX;

        while (front < nums.size() && back < nums.size()) {
            if (sum < target) {
                front++;
                if (front == nums.size()) {
                    return minSize == INT_MAX ? 0 : minSize;
                }
                sum += nums[front];
            } else {
                minSize = min(minSize, front - back + 1);
                sum -= nums[back];
                back++;
            } 
        }

        // Return
        return minSize;
    }
};