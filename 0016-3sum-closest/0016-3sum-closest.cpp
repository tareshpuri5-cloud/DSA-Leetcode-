// class Solution {
// public:
//     int threeSumClosest(vector<int>& nums, int target) {
//         int currentSum;
//           int closestSum = nums[0] + nums[1] + nums[2];    
        

//         for(int i = 0;i<nums.size() ; i++){
//          for(int j = i+1;j<nums.size() ; j++){
//             for (int k=j+1;k<nums.size();k++){
//              currentSum= nums[i]+nums[j]+nums[k];
//                  if (abs(currentSum - target) < abs(closestSum - target)) {
//                         closestSum = currentSum;
//              }
//           }
//         }
//     } 
//         return closestSum;
//     }
// };

#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int closestSum = nums[0] + nums[1] + nums[2]; // initial guess

        for (int i = 0; i < n - 2; i++) {
            int left = i + 1;
            int right = n - 1;

            while (left < right) {
                int currentSum = nums[i] + nums[left] + nums[right];

                if (abs(currentSum - target) < abs(closestSum - target)) {
                    closestSum = currentSum;
                }

                if (currentSum < target) {
                    left++;
                } else if (currentSum > target) {
                    right--;
                } else {
                    return currentSum; // exact match
                }
            }
        }
        return closestSum;
    }
};
