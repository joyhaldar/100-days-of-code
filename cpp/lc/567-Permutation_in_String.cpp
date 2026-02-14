#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.length();
        int n2 = s2.length();

        if (n1 > n2) {
            return false;
        }

        vector<int> s1count(26, 0);
        vector<int> s2count(26, 0);
        int matches = 0;

        for (int i = 0; i < n1; i++) {
            s1count[s1[i] - 'a']++;
            s2count[s2[i] - 'a']++;
        }

        for (int i = 0; i < 26; i++) {
            if (s1count[i] == s2count[i]) {
                matches++;
            }
        }

        if (matches == 26) {
            return true;
        }

        for (int i = n1; i < n2; i++) {
            // increment logic
            int idx = s2[i] - 'a';
            if (s1count[idx] == s2count[idx]) {
                matches--;
            }
            s2count[idx]++;
            if (s1count[idx] == s2count[idx]) {
                matches++;
            }
            // decrement logic
            idx = s2[i-n1] - 'a';
            if (s1count[idx] == s2count[idx]) {
                matches--;
            }
            s2count[idx]--;
            if (s1count[idx] == s2count[idx]) {
                matches++;
            }

            if (matches == 26) {
                return true;
            }
        }
        return false;
    }
};

int main() {
    string s1 = "ab";
    string s2 = "eidbaooo";
    Solution sol;
    bool result = sol.checkInclusion(s1, s2);
    cout << "Permutation in string: " << (result ? "true" : "false") << endl;
    return 0;
}

// To compile  
// g++ 567-Permutation_in_String.cpp -o permutation_in_string

// To run:
// ./permutation_in_string