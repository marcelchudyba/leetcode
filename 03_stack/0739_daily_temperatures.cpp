// Link: https://leetcode.com/problems/daily-temperatures/
// Difficulty: Medium
// Time Complexity: O(n)
// Space Complexity: O(n)
// Date: 2026-05-25

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {

        vector<int> ans;
        for(int i = 0; i < temperatures.size();i++){
            ans.push_back(0);
        }

        //value / index
        std::stack<pair<int,int>> stack;

        for(int i = 1; i < temperatures.size(); i++){
            stack.push({temperatures[i - 1],i - 1});
            while(!stack.empty() && stack.top().first < temperatures[i]){
                auto top = stack.top();
                ans[top.second] = i - top.second;
                stack.pop();
            }
        }
        
        return ans;
    }
};
