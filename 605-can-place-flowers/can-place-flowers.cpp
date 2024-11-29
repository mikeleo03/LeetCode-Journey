class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int i = 0;

        if (flowerbed.size() == 1) {
            return (flowerbed[0] == 0 || (flowerbed[0] == 1 && n == 0));
        }

        while (n > 0 && i < flowerbed.size()) {
            if (flowerbed[i] == 1) {
                i += 2;
            } else {
                if (i + 1 < flowerbed.size()) {
                    if (flowerbed[i + 1] == 1) {
                        i += 3;
                    } else {
                        n--; i += 2;
                    }
                } else {
                    n--; i++;
                }
            }
        }

        return n == 0;
    }
};