class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int highest = 0; int val = 0;

        for (int i = 0; i < gain.size(); i++) {
            val += gain[i];
            highest = max(highest, val);
        }

        return highest;
    }
};