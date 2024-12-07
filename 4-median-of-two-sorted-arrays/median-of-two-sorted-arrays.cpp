class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int pos1 = 0; int pos2 = 0;
        int total = nums1.size() + nums2.size();
        vector<int> res;

        while (pos1 < nums1.size() && pos2 < nums2.size()) {
            if (nums1[pos1] > nums2[pos2]) {
                res.push_back(nums2[pos2]);
                pos2++;
            } else {
                res.push_back(nums1[pos1]);
                pos1++;
            }
        }

        while (pos1 < nums1.size()) {
            res.push_back(nums1[pos1]);
            pos1++;
        }

        while (pos2 < nums2.size()) {
            res.push_back(nums2[pos2]);
            pos2++;
        }

        if (total % 2 == 0) {
            return (double) (res[total / 2] + res[(total / 2) - 1]) / 2;
        } else {
            return (double) res[total / 2];
        }
    }
};