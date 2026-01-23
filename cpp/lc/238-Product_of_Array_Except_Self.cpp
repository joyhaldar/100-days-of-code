#include<iostream>
#include<stdio.h>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res(nums.size());

        int prefix = 1;
        for (int i = 0; i < nums.size(); i++) {
            res[i] = prefix;
            prefix = prefix * nums[i];
        }

        int postfix = 1;
        for (int i = nums.size() - 1; i > -1; i--) {
            res[i] = res[i] * postfix;
            postfix = postfix * nums[i];
        }

        return res;
    }
};

int main() {
    std::vector<int> nums = {1, 2, 3, 4};
    Solution sol;
    std::vector<int> result = sol.productExceptSelf(nums);
    std::cout << "Product of array except self: ";
    for (int num : result) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    return 0;
}

// To compile  
// g++ 238-Product_of_Array_Except_Self.cpp -o product_except_self

// To run:
// ./product_except_self