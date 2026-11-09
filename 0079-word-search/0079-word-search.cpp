class Solution {
public:
    bool searchWord(vector<vector<char>>&board,string word,int row,int col,int index){
       
        if (row < 0 || row >= board.size() || col < 0 || col >= board[0].size()) return false;     
        if(index == word.size()){
            return true;
        }
         char  val = word[index];
        char temp = board[row][col];
        board[row][col]='.';
        //right
            if(col+1<board[0].size()&&board[row][col+1]==val ){
                if(searchWord(board,word,row,col+1,index+1))return true;
            }

        //left
            if( col-1>=0&&board[row][col-1]==val){
                if(searchWord(board,word,row,col-1,index+1))return true;
            }
        //up
            if(row-1>=0 && board[row-1][col]==val ){
                  if(searchWord(board,word,row-1,col,index+1)) return true;
            }
            
        //down
            if(row+1< board.size() && board[row+1][col]==val){
                if(searchWord(board,word,row+1,col,index+1)) return true;
            }

            board[row][col] = temp;
            return false;
    }
    bool solve(vector<vector<char>>& board,string word,int row,int col,int index){
            if (word.size()==1) return true;
            return searchWord(board,word,row,col,1);
    }
    bool exist(vector<vector<char>>& board, string word) {
            int index=0;
            int row,col;
            for(row =0; row< board.size();row++){
                for(col = 0 ;col < board[0].size();col++){
                    if(board[row][col]==word[0]){
                        if(solve(board,word, row, col,index)){
                             return true;
                         }
                    }
                }
            }
            
        return false;
    }
};