// Link: https://leetcode.com/problems/contains-duplicate/
// Difficulty: Easy
// Time Complexity: O(n)
// Space Complexity: O(n)
// Date: 2026-05-08

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        std::unordered_set<int> set;
        
        //reserving memory
        set.reserve(nums.size());

        for(int x: nums){
             if(set.count(x)) return true;
            set.insert(x);
        }

        return false;
    }
};
