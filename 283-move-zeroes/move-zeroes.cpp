class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int front = -1; int back = 0;
        int current = 0;

        while (current < nums.size()) {
            if (nums[current] == 0) {
                if (front == -1) front = current;
            } else {
                if (front != -1) {
                    swap(nums[front], nums[current]);
                    front += 1;
                    back = current;
                }
            }
            
            current++;
        }
    }
};