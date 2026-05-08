// Link: https://leetcode.com/problems/two-sum/
// Difficulty: Easy
// Time Complexity: O(n)
// Space Complexity: O(n)
// Date: 2026-05-08

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //value / index
        std::unordered_map<int,int> map;
        int target_to_sum = 0;

        for(int i = 0; i < nums.size();i++){
            
            target_to_sum = target - nums[i];

            auto first_index = map.find(target_to_sum);

            if(first_index != map.end() && first_index->second != i){
                return {first_index->second,i};
            }
            map.insert({nums[i], i});
        }       

        return {};
        
    }
};