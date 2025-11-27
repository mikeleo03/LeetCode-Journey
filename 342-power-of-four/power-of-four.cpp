class Solution {
public:
    bool isPowerOfFour(int n) {
        long long value = 1;
        while (value <= n) {
            if (value == n) {
                return true;
            }
            value *= 4;
        }

        return false;
    }
};