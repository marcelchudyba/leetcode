// Link: https://leetcode.com/problems/valid-parentheses/
// Difficulty: Easy
// Time Complexity: O(n)
// Space Complexity: O(n)
// Date: 2026-05-07

class Solution {
public:
    bool isValid(string s) {
        
        std::stack<char> opening;
        std::unordered_map<char, char> parentheses;

        parentheses.insert({')', '('});
        parentheses.insert({']', '['});
        parentheses.insert({'}', '{'});
        
        for(int i = 0; i < s.length(); i++){
            char curr = s[i];

            if(curr == '(' || curr == '[' || curr == '{'){
                opening.push(curr);
            }

            if(curr == ')' || curr == ']' || curr == '}'){
                if(opening.empty()) return false;
                char top = opening.top();
                opening.pop();
                if(top != parentheses.at(curr)){
                    return false;
                }
                
            }
        }

        if(!opening.empty()) return false;

        return true;
    }
};