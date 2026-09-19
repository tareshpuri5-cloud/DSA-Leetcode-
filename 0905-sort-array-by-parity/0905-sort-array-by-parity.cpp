class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {

        int left = 0;
        int right = nums.size() -1;

        while (left < right){
            if(nums[left]%2==0){
                
                left ++;
            
                
            }else if(nums[right]%2!=0){
                right--;
                
            }else{
                swap(nums[left],nums[right]);
            left++;
            right--;
            }     
        }
        // while(left<right){
        //     if(nums[left]<nums[right]){
        //         swap(nums[left],nums[right]);
        //     }
        // }

        int boundary =0;
        
        for(int i = 0;i<nums.size();i++){
            if(nums[i]%2==0){
               
                // boundary = i;
            }else{
                 boundary = i;
                break;
            }
        }

        sort(nums.begin(),nums.begin()+boundary);
        sort(nums.begin()+boundary,nums.end());


        return nums;
        
    }
};