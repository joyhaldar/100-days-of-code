#include<iostream>
#include<stdio.h>

class Solution {
public:
    bool containsDuplicate(std::vector<int>& nums) {
        std::unordered_map<int, int> mp;

        for (int x:nums) {
            mp[x]++;
        }
        for (int x:nums) {
            if(mp[x] > 1) {
                return true;
            }
        }
        return false;
    }
};

int main() {
    std::vector<int> nums = {1, 2, 3, 1};
    Solution sol;
    bool result = sol.containsDuplicate(nums);
    std::cout << (result ? "true" : "false") << std::endl;
    return 0;
}

// To compile:  
// g++ 217-Contains\ Duplicate.cpp -o contains_duplicate

// To run:
// ./contains_duplicate