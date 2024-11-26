class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = 0;
        int c = 0;
        for (int num : nums) {
            if (c == 0) n = num;
            num == n ? c++ : c--;
        }
        return n;
    }
};