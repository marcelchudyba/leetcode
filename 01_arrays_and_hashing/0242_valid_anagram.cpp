// Link: https://leetcode.com/problems/valid-anagram/
// Difficulty: Easy
// Time Complexity: O(n)
// Space Complexity: O(n)
// Date: 2026-05-08

class Solution {
public:
    bool isAnagram(string s, string t) {
        
        std::unordered_map<char,int> chars;
    
        if(s.length() != t.length()) return false;

        for(char c: s){
            chars[c]++;
        }
        
        for(char c: t){
            if(chars.find(c) == chars.end() || chars[c] == 0) return false;
            chars[c]--;
        }

        return true;

    }
};
