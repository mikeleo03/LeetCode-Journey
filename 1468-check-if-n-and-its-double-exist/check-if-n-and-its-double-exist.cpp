class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_set<int> set1;

        for (int num : arr) {
            if (set1.count(num * 2) || (num % 2 == 0 && set1.count(num / 2))) return true;
            set1.insert(num);
        }

        return false;
    }
};