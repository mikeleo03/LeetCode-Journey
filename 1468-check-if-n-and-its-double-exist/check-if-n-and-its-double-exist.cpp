class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_map<int, int> set1;

        for (int i = 0; i < arr.size(); i++) {
            set1[arr[i]]++;
        }

        for (int i = 0; i < arr.size(); i++) {
            if (set1.find(2 * arr[i]) != set1.end()) {
                if (arr[i] == 0) {
                    if (set1[0] > 1) {
                        return true;
                    } else { continue; }
                }
                return true;
            }
        }

        return false;
    }
};