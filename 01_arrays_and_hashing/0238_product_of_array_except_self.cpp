// Link: https://leetcode.com/problems/product-of-array-except-self/
// Difficulty: Medium
// Time Complexity: O(n)
// Space Complexity: O(1)
// Date: 2026-05-12

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        vector<int> output;

        int preFix = 1;  
        for(int i = 0; i < nums.size(); i++){
            output.push_back(preFix);
            preFix*= nums[i];
        }   

        int postFix = 1;  

        for(int i = nums.size() - 1; i >= 0; i--){
            output[i]*= postFix;
            postFix *= nums[i];
        }   

        return output;
    }
};
