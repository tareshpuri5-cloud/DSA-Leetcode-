class Solution {
public:
    unordered_map<int, unordered_map<char, bool>> horizontal;
    unordered_map<int, unordered_map<char, bool>> vertical;
    unordered_map<int, unordered_map<char, bool>> cube;
    bool isEmpty(vector<vector<char>>& board,int &row,int &col){
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]=='.'){
                    row = i;
                    col = j;
                    return true;
                }
            }
        }
        return false;
    }
    bool isSafe(int row, int col, char num) {
        int boxIdx = (row / 3) * 3 + (col / 3);

        // Check row, col, and 3x3 cube
        if (horizontal[row][num]) return false;
        if (vertical[col][num]) return false;
        if (cube[boxIdx][num]) return false;

        return true;
    }
    bool sudokuSoln(vector<vector<char>>& board){
        int row,col;
     
        if(!isEmpty(board,row,col)){
            return true;
        }   
        int boxIdx = (row / 3) * 3 + (col / 3);

        for(int i=1;i<=9;i++){
            char num = i+'0';
            if(isSafe(row,col,num)){
                board[row][col] = num;
                horizontal[row][num] = true;
                vertical[col][num] = true;
                cube[boxIdx][num] = true;
                if(sudokuSoln(board)) {
                    return true;
                }
                board[row][col] ='.';
                horizontal[row][num] = false;
                vertical[col][num] = false;
                cube[boxIdx][num] = false;
                

            }
        }
        return false;
    }
    
    void solveSudoku(vector<vector<char>>& board){
        // vector<vector<string>>ans;
        horizontal.clear();
        vertical.clear();
        for (int r = 0; r < 9; r++) {
                    for (int c = 0; c < 9; c++) {
                        if (board[r][c] != '.') {
                            char num = board[r][c];
                            int boxIdx = (r / 3) * 3 + (c / 3);
                            horizontal[r][num] = true;
                            vertical[c][num] = true;
                            cube[boxIdx][num] = true;
                        }
                    }
                }
        sudokuSoln(board);
    }
};