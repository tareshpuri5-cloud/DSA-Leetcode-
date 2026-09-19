class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0;
        int right_max = 0;
        int left_max = 0;
        int water = 0;
       int right = height.size()- 1;
        while(left < right ){
            // if (right < right_max){
            //     right_max = right;
            //     right --;
            // }else if (left > left_max){
            //         left_max = left;
            //         left ++;
            //     }
            // }
            // if ()
            // max(height[right],height[left])
            if (height[left] <= height[right]){
                // height_left = height[left];
                if (left_max<height[left]){
                   left_max = height[left];
                }else{
                    water += left_max-height[left];
                }
                left++;
            }
            else{
                // height_right = height[right];
                if (right_max<height[right]){
                   right_max = height[right];
                }else{
                    water += right_max-height[right];
                }
                right--;
            }
        }
        return water;
    }
};