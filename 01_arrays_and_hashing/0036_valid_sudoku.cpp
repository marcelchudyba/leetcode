// Link: https://leetcode.com/problems/valid-sudoku/
// Difficulty: Medium
// Time Complexity: O(n^2)
// Space Complexity: O(n)
// Date: 2026-05-13

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        for(int i = 0; i < board.size();i++){
            std::unordered_set<char> rows;
            std::unordered_set<char> cols;
            for(int j = 0; j < board[i].size(); j++){
                //rows
                if(!rows.empty() && rows.contains(board[i][j])) return false;
                
                if(board[i][j] != '.') rows.insert(board[i][j]);

                //cols
                if(!cols.empty() && cols.contains(board[j][i])) return false;
                
                if(board[j][i] != '.') cols.insert(board[j][i]);
            }
        }    


        for(int square; square < 9; square++){ 
            std::unordered_set<char> squares;
            for(int i = 0; i < 3; i++){
                for(int j = 0 ; j < 3; j++){
                int col = j + 3 * (square % 3);
                int row = i + 3 *(square / 3);

                if(!squares.empty() && squares.contains(board[row][col])) return false;

                if(board[row][col] != '.') squares.insert(board[row][col]);
                
                }
            }
        }
        return true;
    }
};
