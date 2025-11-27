class Solution {
public:
    bool isPowerOfThree(int n) {
        long long value = 1;
        while (value <= n) {
            if (value == n) {
                return true;
            }
            value *= 3;
        }

        return false;
    }
};