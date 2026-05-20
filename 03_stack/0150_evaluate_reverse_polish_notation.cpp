// Link: https://leetcode.com/problems/evaluate-reverse-polish-notation/
// Difficulty: Medium
// Time Complexity: O(n)
// Space Complexity: O(n)
// Date: 2026-05-20

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        std::stack<int> numbers_stack; 
    
        for(string token : tokens){
            if(token == "*" || token == "-" || token == "+" || token == "/"){
                int right = numbers_stack.top();
                numbers_stack.pop();
                int left = numbers_stack.top() ;
                numbers_stack.pop();

                if(token == "*"){
                    numbers_stack.push(left * right);
                }
                else if(token == "/"){
                    numbers_stack.push(left / right);
                }
                else if(token == "-"){
                    numbers_stack.push(left - right);
                } 
                else if(token == "+"){
                    numbers_stack.push(left + right);
                }

            }
            else{
                numbers_stack.push(stoi(token));
            }
        }
            return numbers_stack.top();
    }
};
