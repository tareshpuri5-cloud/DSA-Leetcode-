class Solution {
public:
    void solve( vector<vector<int>>&result,vector<int>&temp,vector<int>nums,int n){
        result.push_back(temp);
        for (int i = n; i < nums.size(); i++) {
        if (i > n && nums[i] == nums[i - 1]) continue;
            temp.push_back(nums[i]);
            solve(result, temp, nums, i + 1); 
            temp.pop_back();
        }
    }    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>result;
        vector<int>temp;
        sort(nums.begin(), nums.end());
        solve(result, temp, nums, 0);
        return result;
    }
};