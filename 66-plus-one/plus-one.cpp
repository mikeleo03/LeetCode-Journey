class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        if (digits[digits.size() - 1] != 9) {
            digits[digits.size() - 1]++;
        } else {
            int pos = digits.size() - 1;
            while (digits[pos] == 9 && pos > 0) {
                digits[pos] = 0;
                pos--;
            }

            if (pos == 0 && digits[pos] == 9) {
                vector<int> res;
                res.push_back(1);
                for (int i = 0; i < digits.size(); i++) {
                    res.push_back(0);
                }
                return res;
            } else {
                digits[pos]++;
            }
        }

        return digits;
    }
};