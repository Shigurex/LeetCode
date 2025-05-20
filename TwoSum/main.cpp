#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void printVector(const vector<int>& vec) {
    cout << "[";
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i];
        if (i < vec.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;
}


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                int res = nums[i] + nums[j];
                if (res == target) {
                    vector<int> result = {i, j};
                    return result;
                }
            }
        }
        return {};
    }
};

int main() {
    Solution solution;

    vector<int> nums1 = {2, 7, 11, 15};
    int target1 = 9;
    vector<int> result = solution.twoSum(nums1, target1);
    printVector(result);

    vector<int> nums2 = {3, 2, 4};
    int target2 = 6;
    result = solution.twoSum(nums2, target2);
    printVector(result);

    vector<int> nums3 = {3, 3};
    int target3 = 6;
    result = solution.twoSum(nums3, target3);
    printVector(result);
}