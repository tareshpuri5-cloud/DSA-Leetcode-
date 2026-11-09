class Solution {
public:
    bool isSafe(vector<vector<char>>&board,int row,int col,char val){
        //horizontal-loop
        for(int i=0;i<9;i++){
            if(board[row][i]== val){
                return false;
            }
        }
        //vertical-loop
        for(int j=0;j<9;j++){
            if(board[j][col]== val){
                return false;
            }
        }
        int r = row-(row%3);
        int c = col-(col%3);
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(board[r+i][c+j] == val) return false;
            }
        }
        return true;

    }
    bool isEmpty(vector<vector<char>>&board,int &row,int&col){
        //horizonatal loop
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
             if(board[i][j]=='.') {
                row =i;
                col =j;
                return true;
              }
            }
        }
        return false;
    }
    bool solveBoard(vector<vector<char>>&board){
        int row,col;
        if (!isEmpty(board, row, col)) {
            return true;
        }
        for(char i='1';i<='9';i++){
            if(isSafe(board,row,col,i)){
                board[row][col]=i;
           
            if(solveBoard(board)){
                return true;
            }
            board[row][col]='.';
             }
        }
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {


        solveBoard(board);
        
    }
};