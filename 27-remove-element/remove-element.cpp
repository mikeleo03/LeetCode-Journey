class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        // Start with 2 pointer approach
        int front = 0;
        int back = nums.size() - 1;

        if (nums.size() == 0) {
            return 0;
        }

        // Iterate until both met up
        while (back > front) {
            // If back equal to val, then back maju, add counter
            if (nums[back] == val) {
                back--;
            }
            // If front equal to val, then switch value back and front, add counter
            else if (nums[front] == val) {
                int temp = nums[front];
                nums[front] = nums[back];
                nums[back] = temp;
                back--;
            }
            // If none of them, depan maju
            else {
                front++;
            }
        }

        if (nums[back] == val && nums[front] == val) {
            return back;
        }

        // Return size - duplicate occurence
        return back + 1;
    }
};