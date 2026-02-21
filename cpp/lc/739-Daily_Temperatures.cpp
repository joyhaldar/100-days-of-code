#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> res(temperatures.size(), 0);
        stack<pair<int, int>> st; // temp, idx

        for (int i = 0; i < temperatures.size(); i++) {
            while (!st.empty() && temperatures[i] > st.top().first) {
                int idx = st.top().second;
                st.pop();
                res[idx] = i - idx;
            }
            st.push({temperatures[i], i});
        }
        return res;
    }
};

int main() {
    vector<int> temperatures = {73,74,75,71,69,72,76,73};
    int h = 8;
    Solution sol;
    vector<int> result = sol.dailyTemperatures(temperatures);
    cout << "Daily temperatures: ";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;
    return 0;
}

// To compile  
// g++ 739-Daily_Temperatures.cpp -o daily_temperatures

// To run:
// ./daily_temperatures