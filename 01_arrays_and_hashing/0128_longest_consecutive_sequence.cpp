// Link: https://leetcode.com/problems/longest-consecutive-sequence/
// Difficulty: Medium
// Time Complexity: O(n)
// Space Complexity: O(n)
// Date: 2026-05-18

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        std::unordered_set<int> numSet(nums.begin(),nums.end());
        int longest = 0;

        for(int num : numSet){
            if(numSet.find(num - 1) == numSet.end()){
                int temp_size = 1;
                while(numSet.find(num + temp_size) != numSet.end()){
                    temp_size++;
                }

                if(temp_size > longest){
                    longest = temp_size;
                }
            }
        }

        return longest;

    }
};
