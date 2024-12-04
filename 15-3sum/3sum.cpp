#include <algorithm>

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> solution;

        // sort the array
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++) {
            // Skip duplicates for the first number
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            
            int remaining = -1 * nums[i];
            int secPon = i + 1; int thPon = nums.size() - 1;
            while (secPon < thPon) {
                if (nums[secPon] + nums[thPon] > remaining) {
                    thPon--;
                } else if (nums[secPon] + nums[thPon] < remaining) {
                    secPon++;
                } else {
                    // Found a triplet
                    solution.push_back({nums[i], nums[secPon], nums[thPon]});

                    // Skip duplicates for the second and third numbers
                    while (secPon < thPon && nums[secPon] == nums[secPon + 1]) secPon++;
                    while (secPon < thPon && nums[thPon] == nums[thPon - 1]) thPon--;

                    secPon++;
                    thPon--;
                }
            }
        }

        return solution;
    }
};