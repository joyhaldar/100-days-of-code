#include<iostream>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::unordered_map<int, int> m1;

        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            if (m1.find(complement) != m1.end()) {
                return {m1[complement], i};
            }
            else {
                m1[nums[i]] = i;
            }
        }
        return {};
    }
};

int main() {
    std::vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    Solution sol;
    std::vector<int> result = sol.twoSum(nums, target);
    for (int i = 0; i < result.size(); ++i) {
        std::cout << result[i];
        if (i != result.size() - 1) std::cout << ", ";
    }
    std::cout << std::endl;
    return 0;
}

// To compile:  
// g++ 1-Two_Sum.cpp -o two_sum

// To run:
// ./two_sum