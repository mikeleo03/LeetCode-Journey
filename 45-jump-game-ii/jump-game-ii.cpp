class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int jumps = 0, far = 0, farthest = 0;

        for (int i = 0; i < n - 1; i++) {
            farthest = max(farthest, i + nums[i]);
            if (i == far) {
                jumps++;
                far = farthest;
            }
            if (far >= n - 1) break;
        }
        return jumps;
    }
};