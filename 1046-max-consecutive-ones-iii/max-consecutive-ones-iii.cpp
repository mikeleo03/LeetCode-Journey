class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int maxlen = 0; int len = 0;
        int flipped = 0; int left = 0; int right = 0;

        while (right < nums.size()) {
            if (nums[right] == 1) {
                len++;
            } else {
                flipped++; len++;
                if (flipped > k) {
                    while (nums[left] == 1) {
                        left++; len--;
                    }
                    left++; len--;
                }
            }

            maxlen = max(maxlen, len);
            right++;
        }

        return maxlen;
    }
};