#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        if (t == "") {
            return "";
        }
        unordered_map<char, int> count, window;
        for (char c: t) {
            count[c]++;
        }
        int have = 0, need = count.size();
        int l = 0, resl = -1, resr = -1, reslen = INT_MAX;
        for (int r = 0; r < s.length(); r++) {
            window[s[r]]++;

            if (count.count(s[r]) && count[s[r]] == window[s[r]]) {
                have++;
            }

            while (have == need) {
                if (r - l + 1 < reslen) {
                    reslen = ( r - l + 1);
                    resl = l;
                    resr = r;
                }

                window[s[l]]--;
                if (count.count(s[l]) && window[s[l]] < count[s[l]]) {
                    have--;
                }
                l++;
            }
        }
        if (reslen != INT_MAX) {
            return s.substr(resl, reslen);
        }
        return "";
    }
};

int main() {
    std::string s = "ADOBECODEBANC";
    std::string t = "ABC";
    Solution sol;
    std::string result = sol.minWindow(s, t);
    std::cout << "Minimum window substring: " << result << std::endl;
    return 0;
}

// To compile:  
// g++ 76-Minimum_Window_Substring.cpp -o minimum_window_substring

// To run:
// ./minimum_window_substring