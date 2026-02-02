#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0;
        int r = height.size() - 1;
        int res = 0;
        int leftMax = height[l];
        int rightMax = height[r];
        while (l < r) {
            if (leftMax < rightMax) {
                l++;
                leftMax = max(leftMax, height[l]);
                res += leftMax - height[l];
            } else {
                r--;
                rightMax = max(rightMax, height[r]);
                res += rightMax - height[r];
            }
        }
        return res;
    }
};

int main() {
    std::vector<int> nums = {0,1,0,2,1,0,1,3,2,1,2,1};
    Solution sol;
    int result = sol.trap(nums);
    std::cout << "Maximum area: " << result << std::endl;
    return 0;
}

// To compile  
// g++ 42-Trapping_Rain_Water.cpp -o trapping_rain_water

// To run:
// ./trapping_rain_water