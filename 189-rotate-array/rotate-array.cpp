class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        // Constraint check
        if (nums.empty()) return;

        // Modulo check lol
        int r = k % nums.size();

        // 3 steps
        // 1. Balikin semua
        for (int i = 0; i < nums.size() / 2; i++) {
            int num = nums[i];
            nums[i] = nums[nums.size() - i - 1];
            nums[nums.size() - i - 1] = num;
        }

        // 2. Balikin depannya
        for (int i = 0; i < r / 2; i++) {
            int num = nums[i];
            nums[i] = nums[r - i - 1];
            nums[r - i - 1] = num;
        }

        // 3. Balikin belakangnya
        for (int i = 0; i < (nums.size() - r) / 2; i++) {
            int num = nums[r + i];
            nums[r + i] = nums[nums.size() - i - 1];
            nums[nums.size() - i - 1] = num;
        }
    }
};