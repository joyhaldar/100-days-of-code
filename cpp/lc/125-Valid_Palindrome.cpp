#include<iostream>

class Solution {
public:
    bool isPalindrome(std::string s) {
        int l = 0, r = s.length() - 1;
        while (l < r) {
            while (l < r and !isalnum(s[l])) {
                l++;
            }
            while (l < r and !isalnum(s[r])) {
                r--;
            }
            if (tolower(s[l]) != tolower(s[r])) {
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
};

int main() {
    std::string s = "A man, a plan, a canal: Panama";
    Solution sol;
    bool result = sol.isPalindrome(s);
    std::cout << (result ? "true" : "false") << std::endl;
    return 0;
}

// To compile:  
// g++ 125-Valid_Palindrome.cpp -o valid_palindrome

// To run:
// ./valid_palindrome