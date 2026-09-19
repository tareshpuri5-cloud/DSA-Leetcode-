class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int left =0;
        int right = nums.size()-1;
        int pos = nums.size()-1;
        vector<int> result(nums.size());

        while (left<=right){
           int leftsq =  nums[left]*nums[left];
           int rightsq = nums[right]*nums[right];
         
            if (leftsq < rightsq){
                result[pos]= rightsq;
                right --;

            }else{
                result[pos] = leftsq;
                left ++;
            }
            pos --;
           
        }
        return result;
    }
};