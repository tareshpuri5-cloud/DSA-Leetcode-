class Solution {
public:
   bool isSafe(vector<vector<char>>&board,int row,int col){
      int n = board.size();
      //i have to check three directions
      for(int i=0;i<col;i++){
        if(board[row][i]=='Q'){
            //this means attack ho rha hai!!
            return false;
        }
      }
      int r = row-1;
        int c = col-1;
      //upper diagonal
      while(r>=0 && c>=0){
        

        if(board[r][c]=='Q'){
            //this means attack ho rha hai!!
            return false;
        }
        r--;
        c--;
      }//lower diagonal
        int x=row+1;
        int y=col-1;
      while(x<n && y>=0){

        if(board[x][y]=='Q'){
            //this means attack ho rha hai!!
            return false;
        }
        x++;
        y--;
      }

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
                solveBoard(board,ans,col+1,n);
                board[row][col]='.';
            }
        }

    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        int col =0;
       vector<vector<char>> board(n, vector<char>(n, '.'));
        solveBoard(board,ans,col,n);
        return ans;  
    }
};