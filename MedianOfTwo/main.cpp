class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int nums1Index = 0;
        int nums2Index = 0;

        int nums1Size = nums1.size();
        int nums2Size = nums2.size();
        vector<int> total;

        while (true) {
            if (nums1Index == nums1Size && nums2Index == nums2Size) {
                break ;
            } else if (nums1Index == nums1Size) {
                total.push_back(nums2[nums2Index++]);
            } else if (nums2Index == nums2Size) {
                total.push_back(nums1[nums1Index++]);
            } else {
                if (nums1[nums1Index] < nums2[nums2Index]) {
                    total.push_back(nums1[nums1Index++]);
                } else {
                    total.push_back(nums2[nums2Index++]);
                }
            }
        }

        int totalSize = nums1Size + nums2Size;
        if (totalSize % 2 == 0 && totalSize > 1) {
            return float(total[totalSize / 2 - 1] + total[totalSize / 2]) / 2;
        } else {
            return total[totalSize / 2];
        }
    }
};