#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        int res = 0, l = 0, maxFreq = 0;
        vector<int> count(26, 0);

        for (int r = 0; r < s.length(); r++) {
            count[s[r] - 'A']++;
            maxFreq = max(maxFreq, count[s[r] - 'A']);
            while ((r - l + 1) - maxFreq > k) {
                count[s[l] - 'A']--;
                l++;
            }
            res = max(res, (r - l + 1));
        }
        return res;
    }
};

int main() {
    string s = "ABAB";
    int k = 2;
    Solution sol;
    int result = sol.characterReplacement(s, k);
    cout << "Longest repeating character replacement: " << result << endl;
    return 0;
}

// To compile  
// g++ 424-Longest_Repeating_Character_Replacement.cpp -o longest_repeating_character_replacement

// To run:
// ./longest_repeating_character_replacement