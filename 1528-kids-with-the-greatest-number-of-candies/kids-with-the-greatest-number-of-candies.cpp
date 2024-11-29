class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> result;

        // satu kali iterate max nya berapa
        int max = candies[0];
        for (int i = 1; i < candies.size(); i++) {
            if (candies[i] > max) max = candies[i];
        }

        // iterate back to get the bools
        for (int i = 0; i < candies.size(); i++) {
            result.push_back(candies[i] + extraCandies >= max);
        }

        return result;
    }
};