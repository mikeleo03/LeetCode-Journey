class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxlen = 0;
        int left = 0; int right = 0; bool flipped = false;

        while (right < nums.size()) {
            if (nums[right] == 0) {
                if (flipped) {
                    while (nums[left] == 1) left++;
                    left++;
                }
                flipped = true;
            }

            right++;
            maxlen = max(maxlen, right - left);
        }

        return maxlen - 1;
    }
};