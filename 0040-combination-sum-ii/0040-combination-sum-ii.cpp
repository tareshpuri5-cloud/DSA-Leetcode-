class Solution {
public:
    void solve(vector<int>& candidates,vector<vector<int>>&result,int start, int target,vector<int>&current){
        if(target==0) {
            result.push_back(current);
            return;
            }
       for(int i=start;i<candidates.size();i++){
        if(candidates[i]>target){
            break;
        }
        
        if(i>start && candidates[i-1]==candidates[i]) continue;
        current.push_back(candidates[i]);

        solve(candidates,result,i+1,target-candidates[i],current);
        current.pop_back();
       }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>>result;
        sort(candidates.begin(),candidates.end());
        vector<int>current;
        solve(candidates,result,0,target,current);
        return result;
    }
};