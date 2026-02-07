#include<iostream>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> charSet;
        int l = 0;
        int res = 0;

        for (int r = 0; r < s.length(); r++) {
            while (charSet.count(s[r]) != 0) {
                charSet.erase(s[l]);
                l++;
            }
            charSet.insert(s[r]);
            res = max(res, r - l + 1);
        }
        return res;
    }
};

int main() {
    std::string s = "abcabcbb";
    Solution sol;
    int result = sol.lengthOfLongestSubstring(s);
    std::cout << result << std::endl;
    return 0;
}

// To compile:  
// g++ 3-Longest_Substring_Without_Repeating_Characters.cpp -o longest_substring

// To run:
// ./longest_substring