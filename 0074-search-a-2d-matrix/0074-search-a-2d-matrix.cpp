
class Solution { 
public: 
    bool searchMatrix(vector<vector<int>>& matrix, int target) { 
        int m = matrix.size(); 
        int n = matrix[0].size(); 
        
        int start = 0; 
        int end = (m * n) - 1; 
        
        while (start <= end) { 
            int mid = start + (end - start) / 2; 
            int row = mid / n; 
            int col = mid % n; 
            
            if (matrix[row][col] == target) { 
                return true; 
            } 
            else if (target < matrix[row][col]) { 
                end = mid - 1; 
            } 
            else { 
                start = mid + 1; 
            } 
        } 
        
        return false; 
    } 



     //     for(int i = 0; i < m; i++){ 
    //         for (int j = 0; j < n; j++){ 
    //             if (matrix[i][j] == target) { 
    //                 return true;
    //             } 
                
    //         } 
    //     } 
        
    //     return false;
};