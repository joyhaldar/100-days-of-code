#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int r = 0;
        for (int i = 0; i < piles.size(); i++) {
            if (piles[i] > r) {
                r = piles[i];
            }
        }
        int res = r;
        while (l <= r) {
            int k = (l + r) / 2;
            long hours = 0;
            for (int i = 0; i < piles.size(); i++) {
                hours = hours + (piles[i] + k - 1) / k;
            }
            if (hours <= h) {
                res = k;
                r = k - 1;
            } else {
                l = k + 1;
            }
        }
        return res;
    }
};

int main() {
    vector<int> piles = {3, 6, 7, 11};
    int h = 8;
    Solution sol;
    int result = sol.minEatingSpeed(piles, h);
    cout << "Minimum eating speed: " << result << endl;
    return 0;
}

// To compile  
// g++ 875-Koko_Eating_Bananas.cpp -o koko_eating_bananas

// To run:
// ./koko_eating_bananas