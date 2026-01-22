#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> cnt;
        vector<vector<int>> freq(nums.size() + 1);
        vector<int> res;

        for (int n: nums) {
            cnt[n]++;
        }

        for (auto& [n, c]: cnt) {
            freq[c].push_back(n);
        }

        for (int i = freq.size() - 1; i > 0; i--) {
            for (int n: freq[i]) {
                res.push_back(n);
                if (res.size() == k) {
                    return res;
                }
            }
        }
        return res;
    }
};

int main(int argc, char* argv[]) {
    vector<int> nums = {1, 1, 1, 2, 2, 3};
    int k = 2;
    
    Solution sol;
    vector<int> result = sol.topKFrequent(nums, k);
    
    cout << "Top " << k << " frequent elements: ";
    for (int num : result) {
        cout << num << ", ";
    }
    cout << endl;
    
    return 0;
}

// To compile:  
// g++ -std=c++17 347-Top_K_Frequent_Elements.cpp -o top_k_frequent_elements

// To run:
// ./top_k_frequent_elements