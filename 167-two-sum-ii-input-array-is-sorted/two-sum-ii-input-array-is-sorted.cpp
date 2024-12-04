class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int front = 0;
        int back = numbers.size() - 1;
        vector<int> res;

        while (front < back) {
            if (numbers[front] + numbers[back] > target) {
                back--;
            } else if (numbers[front] + numbers[back] < target) {
                front++;
            } else {
                res.push_back(front + 1); res.push_back(back + 1);
                return res;
            }
        }

        res.push_back(front + 1); res.push_back(back + 1);
        return res;
    }
};