// Link: https://leetcode.com/problems/min-stack/
// Difficulty: Medium
// Time Complexity: O(1)
// Space Complexity: O(n)
// Date: 2026-05-19

class MinStack {
public:
    std::vector<int> stack; 
    int top_index;
    int min_value;
    std::vector<int> min_values;

    MinStack() {
        min_values = {};
        stack = {};
        top_index = -1;
        min_value = NULL;
    }
    
    void push(int val) {
        if(stack.empty()) min_value = val;
        else min_value = min_values[top_index] > val ? val : min_values[top_index];

        stack.push_back(val);
        min_values.push_back(min_value);
        top_index++;
    }
    
    void pop() {
        if(stack.empty()){
            return;
        }
        stack.pop_back();
        min_values.pop_back();
        top_index--;
    }
    
    int top() {
       if(stack.empty()){
        return NULL;   
       }
        return stack[top_index];
    }
    
    int getMin() {
       if(stack.empty() || min_values.empty()){
        return NULL;   
       }
        return min_values[top_index];      
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
