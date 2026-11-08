class Solution {
public:
    int count=0;
    unordered_map<int,bool>hzcheck;
    unordered_map<int,bool>updiacheck;
    unordered_map<int,bool>lowdiacheck;
    bool isSafe(vector<vector<char>>&board,int row,int col){
            if(hzcheck[row]==true) return false;
            if(updiacheck[row-col]==true) return false;
            if(lowdiacheck[row+col]==true) return false;
        return true;
    }
    // void storeSol(vector<vector<char>>&board,vector<vector<string>>&ans,int col){
    //     vector<string>temp;
    //     int n= board.size();
    //     for(int col=0;col<n;col++){
    //         // string output;
    //         for(int row=0;row<n;row++){
    //            char ch = board[row][col];
    //         //    output.push_back(ch);
    //         }
    //         // temp.push_back(output);
    //     }
    //     // ans.push_back(temp);
    //     count ++;
    // }
    void solveBoard(vector<vector<char>>&board,vector<vector<string>>&ans,int col,int n){
        if (col>=n){
            // storeSol(board,ans,col);
            count++;
            return;
        }
        for(int row=0;row<n;row++){
            if(isSafe(board,row,col)){
                board[row][col]='Q';
                hzcheck[row]=true;
                updiacheck[row-col]=true;
                lowdiacheck[row+col]=true;
                solveBoard(board,ans,col+1,n);
                board[row][col]='.';
                hzcheck[row]=false;
                updiacheck[row-col]=false;
                lowdiacheck[row+col]=false;
            }
        }

    }
int totalNQueens(int n) {
        vector<vector<string>>ans;
        int col=0;
        vector<vector<char>>board(n, vector<char>(n, '.'));
        solveBoard(board,ans,col,n);
        hzcheck.clear();
        updiacheck.clear();
        lowdiacheck.clear();
      return count;
    }
};