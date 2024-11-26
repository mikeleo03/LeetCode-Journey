class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;

        int num = nums[0];
        int pos = 1;
        for (int i = 1; i < nums.size(); i++) {
            // Kalo nilainya beda, ganti nums nya
            if (nums[i] != num) {
                nums[pos] = nums[i];
                num = nums[pos++];
            }
        }

        return pos;
    }
};