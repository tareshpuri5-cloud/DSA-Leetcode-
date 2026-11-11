class Solution {
public:
    void solve(int k,int n, vector<vector<int>>&result,vector<int>&temp,int index){
        int min = (k*(k-1))/2;
        int start = index;
        int target = n;

    
        // if(n==1 || min) return;
        if (temp.size() == k) {
            if (target == 0) {
                result.push_back(temp);
            }
            return;
        }        
        for(int i=start;i<=9;i++){
        if(i>n) break;
        temp.push_back(i);
        solve(k,n-i,result,temp,i+1);
        temp.pop_back();

        }
        
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>result;
        vector<int>temp;
        solve(k,n,result,temp,1);
        return result;
    }
};