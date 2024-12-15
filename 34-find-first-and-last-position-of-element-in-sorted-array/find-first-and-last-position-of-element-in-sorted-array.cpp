class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int front = 0; int back = nums.size() - 1;

        if (nums.size() == 0) return {-1, -1};

        while (front < nums.size()) {
            if (nums[front] < target) {
                front++;
            } else {
                break;
            }
        }

        while (back > 0) {
            if (nums[back] > target) {
                back--;
            } else {
                break;
            }
        }

        if ((front <= back) && (nums[front] == target) && (nums[back] == target)) {
            return {front, back};
        } else {
            return {-1, -1};
        }
    }
};