class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k = 1;
        int v = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != v) {
                nums[k] = nums[i];
                v = nums[k];
                k++;
            }
        }
        return k;
    }
};