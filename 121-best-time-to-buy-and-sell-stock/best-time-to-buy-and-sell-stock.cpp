class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int a = prices[0]; int z = 0;

        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] < a) {
                a = prices[i];
            } else {
                int p = prices[i] - a;
                if (p > z) {
                    z = p;
                }
            }
        }

        return z;
    }
};