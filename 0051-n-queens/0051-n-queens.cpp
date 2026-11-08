class Solution {
public:

    unordered_map<int,bool>leftHorizontalcheck;   
    unordered_map<int,bool>upperdiagonalcheck;
    unordered_map<int,bool>lowerdiagonalcheck;
   bool isSafe(vector<vector<char>>&board,int row,int col){
      int n = board.size();
      if(leftHorizontalcheck[row]==true) return false;
       if(upperdiagonalcheck[n-1+row-col]==true) return false;
       if(lowerdiagonalcheck[row+col]==true) return false;
       return true; 
    }
    void storeSolution(vector<vector<char>>&board,vector<vector<string>>&ans,int n){
        //output var
      vector<string>temp;
        for(int col=0;col<n;col++){
            string output;
                for(int row=0;row<n;row++){
                    char ch = board[row][col];
                    output.push_back(ch);
                }
                temp.push_back(output);   
        }
        ans.push_back(temp);
    }
    void solveBoard(vector<vector<char>>&board,vector<vector<string>>&ans,int col,int n){
        //base case
        if(col>=n){
            storeSolution(board,ans,n);
            return;
        }
        for(int row=0;row<n;row++){
            if(isSafe(board,row,col)){
                board[row][col]='Q';
                leftHorizontalcheck[row]= true;
                upperdiagonalcheck[n-1+row-col]= true;
                lowerdiagonalcheck[row+col]= true;
                solveBoard(board,ans,col+1,n);
                board[row][col]='.';
                leftHorizontalcheck[row]= false;
                upperdiagonalcheck[n-1+row-col]= false;
                lowerdiagonalcheck[row+col]= false;

            }
        }

    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        int col =0;
        leftHorizontalcheck.clear();
        upperdiagonalcheck.clear();
        lowerdiagonalcheck.clear();
       vector<vector<char>> board(n, vector<char>(n, '.'));
        solveBoard(board,ans,col,n);
        return ans;  
    }
};