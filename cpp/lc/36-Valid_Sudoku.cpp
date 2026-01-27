#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <map>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int, unordered_set<char>> rows;
        unordered_map<int, unordered_set<char>> cols;
        map<pair<int, int>, unordered_set<char>> squares;

        for (int r = 0; r < 9; r++) {
            for (int c = 0; c < 9; c++) {
                char val = board[r][c];
                if (val == '.') {
                    continue;
                }
                if (rows[r].count(val) != 0 || 
                cols[c].count(val) != 0 || 
                squares[{r / 3, c / 3}].count(val) != 0) {
                    return false;
                }
                rows[r].insert(val);
                cols[c].insert(val);
                squares[{r / 3, c / 3}].insert(val);
            }
        }
        return true;
    }
};

int main() {
    vector<vector<char>> board = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };
    
    Solution sol;
    bool result = sol.isValidSudoku(board);
    cout << "Is Valid Sudoku: " << (result ? "true" : "false") << endl;
    return 0;
}

// To compile  
// g++ 36-Valid_Sudoku.cpp -o valid_sudoku

// To run:
// ./valid_sudoku