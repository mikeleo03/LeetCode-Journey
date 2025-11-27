class Solution {
public:
    int smallestNumber(int n) {
        int value = 1;
        while (value <= n) {
            value *= 2;
        }

        return value - 1;
    }
};