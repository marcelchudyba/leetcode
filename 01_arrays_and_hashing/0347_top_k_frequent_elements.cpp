// Link: https://leetcode.com/problems/top-k-frequent-elements/
// Difficulty: Medium
// Time Complexity: O(n)
// Space Complexity: O(n)
// Date: 2026-05-11

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::unordered_map<int, int> mp;

        vector<pair<int,int>> vc;


        for(const int& num: nums){
            mp[num]++;
        }

        for(const auto & p : mp){
            vc.push_back({p.second,p.first});
        }

        sort(vc.begin(), vc.end());

        vector<int> ans;
        for(int i = 0; i < k; i++){
            auto back = vc.back();
            vc.pop_back();
            ans.push_back(back.second);
        }
            
        return ans;

    }
};
