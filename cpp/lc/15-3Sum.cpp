#include<iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;

        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            int l = i;
            int r = nums.size() - 1;
            while (l < r) {
                int cur = nums[i] + nums[l] + nums[r];
                if (cur > 0) {
                    r--;
                } else if (cur < 0) {
                    l++;
                } else {
                    res.push_back({nums[i], nums[l], nums[r]});
                    l++;
                    while (nums[l] == nums[l - 1] && l < r) {
                        l++;
                    }
                }
            }
        }
        return res;
    }
};

int main() {
    std::vector<int> nums = {-1, 0, 1, 2, -1, -4};
    Solution sol;
    std::vector<std::vector<int>> result = sol.threeSum(nums);
    for (int i = 0; i < result.size(); ++i) {
        std::cout << "[";
        for (int j = 0; j < result[i].size(); ++j) {
            std::cout << result[i][j];
            if (j != result[i].size() - 1) std::cout << ", ";
        }
        std::cout << "]";
        if (i != result.size() - 1) std::cout << ", ";
    }
    std::cout << std::endl;
    return 0;
}

// To compile:  
// g++ 15-3Sum.cpp -o 15-3Sum
// To run:
// ./15-3Sum