#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0;
        int r = height.size() - 1;
        int res = 0;
        
        while (l < r) {
            int cur = (r - l) * min(height[l], height[r]);
            res = max(res, cur);
            if (height[l] < height[r]) {
                l++;
            } else if (height[l] > height[r]) {
                r--;
            } else {
                l++;
            }
        }
        return res;
    }
};

int main() {
    std::vector<int> nums = {1,8,6,2,5,4,8,3,7};
    Solution sol;
    int result = sol.maxArea(nums);
    std::cout << "Maximum area: " << result << std::endl;
    return 0;
}

// To compile  
// g++ 11-Container_With_Most_Water.cpp -o container_with_most_water

// To run:
// ./container_with_most_water