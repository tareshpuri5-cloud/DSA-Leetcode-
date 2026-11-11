class Solution {
public:
    void solve(vector<vector<int>>&result,vector<int>&temp,vector<int>nums,int n){

        int k= nums.size();
        result.push_back(temp);
        for(int i=n;i<k;i++){
            temp.push_back(nums[i]);
            solve(result,temp,nums,i+1);
            temp.pop_back();

        }

    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int>temp;
        solve(result,temp,nums,0);
        return result;
    }
};