
#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numSet(nums.begin(), nums.end());
        int longest = 0;

        for (int n: numSet) {
            if (numSet.count(n - 1) == 0) {
                int length = 0;
                while (numSet.count(n + length) == 1) {
                    length++;
                }
                longest = max(length, longest);
            }
        }
        return longest;
    }
};

int main() {
    std::vector<int> nums = {100,4,200,1,3,2};
    Solution sol;
    int result = sol.longestConsecutive(nums);
    std::cout << "Longest consecutive sequence length: " << result << std::endl;
    return 0;
}

// To compile  
// g++ 128-Longest_Consecutive_Sequence.cpp -o longest_consecutive_sequence

// To run:
// ./longest_consecutive_sequence