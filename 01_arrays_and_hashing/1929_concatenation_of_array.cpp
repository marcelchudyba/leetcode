// Link: https://leetcode.com/problems/concatenation-of-array/
// Difficulty: Easy
// Time Complexity: O(n)
// Space Complexity: O(n)
// Date: 2026-05-10

class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> output;

        for(int i = 0; i < nums.size();i++){
            output.push_back(nums[i]);
        }
        for(int i = 0; i < nums.size();i++){
            output.push_back(nums[i]);
        }
        
        return output;
    }
};
