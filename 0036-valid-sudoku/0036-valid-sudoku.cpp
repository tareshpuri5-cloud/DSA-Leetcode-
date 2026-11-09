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


    bool isValidSudoku(vector<vector<char>>& board) {
        int n=9;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(board[i][j] != '.'){
                    char val=board[i][j];
                    board[i][j]='.';//so it doesnt compare the val by itself thats why we rplaced it with '.' and then if we find any similar value to it we return false and then the board is not valid  
                    if(!isSafe(board,i,j,val)){
                        
                        return false;
                    }//if we dont find any value with val then we again replace the value at i and j with val;
                    board[i][j]=val;
                } 

            }

        }
        return true;
    }

};