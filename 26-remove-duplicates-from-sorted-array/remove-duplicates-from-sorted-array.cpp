class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;

        int v = nums[0];
        int k = 1;
        for (int i = 1; i < nums.size(); i++) {
            // Kalo nilainya beda, ganti nums nya
            if (nums[i] != v) {
                nums[k] = nums[i];
                v = nums[k];
                k++;
            }
        }

        return k;
    }
};