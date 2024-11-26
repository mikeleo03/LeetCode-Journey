class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;

        int num = nums[0]; // the number
        int k = 1; // the position
        int count = 1; // the occurences

        for (int i = 1; i < nums.size(); i++) {
            // Kalo sama, cek frekuensi
            if (nums[i] == num) {
                // Kalo blom 2, tambahin aja
                if (count < 2) {
                    nums[k] = nums[i];
                    count++;
                    k++;
                }
            } else {
                // Kalo beda, assign num sama yang baru
                nums[k] = nums[i];
                num = nums[k];
                k++;
                count = 1;
            }
        }

        return k;
    }
};