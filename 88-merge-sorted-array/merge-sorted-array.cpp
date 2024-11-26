class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // Let's start with 2 pointers approach
        int p = m - 1; // pointing to last element from the first array
        int q = n - 1; // pointing to last element from the second array
        int r = m + n - 1; // pointing to the position of the result (initially on last)

        // Try to iterate from the last element
        // Get the bigger one to be placed on the last position of the 1st array
        while (p >= 0 && q >= 0) {
            if (nums1[p] >= nums2[q]) {
                nums1[r] = nums1[p]; // placing the biggest from nums1 to the last
                p--;
            } else {
                nums1[r] = nums2[q];
                q--;
            }
            r--;
        }

        while (q >= 0) {
            nums1[r] = nums2[q];
            q--;
            r--;
        }
    }
};