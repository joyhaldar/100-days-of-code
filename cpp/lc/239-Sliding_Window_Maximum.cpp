#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> res;

        for (int i = 0; i < nums.size(); i++) {
            if (!dq.empty() && dq.front() <= (i - k)) {
                dq.pop_front();
            }
            while (!dq.empty() && nums[dq.back()] <= nums[i]) {
                dq.pop_back();
            }
            dq.push_back(i);
            if (i >= (k - 1)) {
                res.push_back(nums[dq.front()]);
            }
        }
        return res;
    }
};

int main(int argc, char* argv[]) {
    vector<int> nums = {1,3,-1,-3,5,3,6,7};
    int k = 3;
    
    Solution sol;
    vector<int> result = sol.maxSlidingWindow(nums, k);
    
    cout << "Sliding window maximums: ";
    for (int num : result) {
        cout << num << ", ";
    }
    cout << endl;
    
    return 0;
}

// To compile:  
// g++ -std=c++17 239-Sliding_Window_Maximum.cpp -o sliding_window_maximum

// To run:
// ./sliding_window_maximum