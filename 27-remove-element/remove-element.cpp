class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        // Start with 2 pointer approach
        int front = 0;
        int back = nums.size() - 1;
        int counter = 0;

        if (nums.size() == 0) {
            return 0;
        }
        
        if (nums.size() == 1) {
            return nums[0] == val ? 0 : 1;
        }

        // Iterate until both met up
        while (back > front) {
            // If both equal to val, then back maju
            if (nums[back] == val && nums[front] == val) {
                back--;
            }
            // If back equal to val, then back maju, add counter
            else if (nums[back] == val) {
                back--;
                counter++;
            }
            // If front equal to val, then switch value back and front, add counter
            else if (nums[front] == val) {
                int temp = nums[front];
                nums[front] = nums[back];
                nums[back] = temp;
                counter++;
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
        // return nums.size() - counter;
        return back + 1;
    }
};