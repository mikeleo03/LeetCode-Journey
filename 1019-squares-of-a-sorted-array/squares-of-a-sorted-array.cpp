class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> res;
        int neg = INT_MIN; 
        int pos = INT_MAX;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] < 0) {
                neg = i;
            } else {
                pos = i;
                break;
            }
        }

        while (pos < nums.size() && neg >= 0) {
            int sqpos = nums[pos] * nums[pos];
            int sqneg = nums[neg] * nums[neg];

            if (sqpos <= sqneg) {
                res.push_back(sqpos);
                pos++;
            } else {
                res.push_back(sqneg);
                neg--;
            }
        }

        while (pos < nums.size()) {
            int sqpos = nums[pos] * nums[pos];
            res.push_back(sqpos);
            pos++;
        }

        while (neg >= 0) {
            int sqneg = nums[neg] * nums[neg];
            res.push_back(sqneg);
            neg--;
        }

        return res;
    }
};