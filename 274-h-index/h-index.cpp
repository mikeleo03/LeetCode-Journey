class Solution {
public:
    int hIndex(vector<int>& citations) {
        // Step 1: Sort the citations array in descending order
        sort(citations.rbegin(), citations.rend());

        int h = 0;
        for (int i = 0; i < citations.size(); i++) {
            int nowH = min((i + 1), citations[i]);
            if (nowH > h) {
                h = nowH;
            } else { break; }
        }

        return h;
    }
};