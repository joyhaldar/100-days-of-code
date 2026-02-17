#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (nums[mid] < target) {
                l = mid + 1;
            } else if (nums[mid] > target) {
                r = mid - 1;
            } else {
                return mid;
            }
        }
        return -1;
    }
};

int main() {
    vector<int> nums = {-1,0,3,5,9,12};
    int target = 9;
    Solution sol;
    int result = sol.search(nums, target);
    cout << "Element found at index: " << result << endl;
    return 0;
}

// To compile  
// g++ 704-Binary_Search.cpp -o binary_search

// To run:
// ./binary_search