#include<iostream>
// #include<stdio.h>

class Solution {
public:
    bool isAnagram(std::string s, std::string t) {
        std::unordered_map<int, int> m1;
        std::unordered_map<int, int> m2;

        if (s.size() != t.size()) {
            return false;
        }
        for (int i = 0; i < s.size(); i++) {
            m1[s[i]]++;
            m2[t[i]]++;
        }
        if (m1 == m2) {
            return true;
        }
        return false;
    }
};

int main() {
    std::string s = "anagram";
    std::string t = "nagaram";
    Solution sol;
    bool result = sol.isAnagram(s, t);
    std::cout << (result ? "true" : "false") << std::endl;
    return 0;
}

// To compile:  
// g++ 242-Valid_Anagram.cpp -o valid_anagrams

// To run:
// ./valid_anagrams