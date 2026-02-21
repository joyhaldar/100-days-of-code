#include<iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char> map = {
            {'}', '{'},
            {']', '['},
            {')', '('},
        };
        stack<char> st;

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                st.push(s[i]);
            } else {
                if (!st.empty() && st.top() == map[s[i]]) {
                    st.pop();
                } else {
                    return false;
                }
            }
        }
        if (!st.empty()) {
            return false;
        }
        return true;
    }
};

int main() {
    std::string s = "{[()]}";
    Solution sol;
    bool result = sol.isValid(s);
    std::cout << "Is valid: " << (result ? "true" : "false") << std::endl;
    return 0;
}

// To compile  
// g++ 20-Valid_Parentheses.cpp -o valid_parentheses

// To run:
// ./valid_parentheses