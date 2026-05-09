// Link: https://leetcode.com/problems/group-anagrams/
// Difficulty: Medium
// Time Complexity: O(n * k log k)
// Space Complexity: O(n * k)
// Date: 2026-05-09

class Solution {
public: 
        vector<vector<string>> groupAnagrams(vector<string>& strs) {
       
        std::unordered_map<std::string,vector<string>> anagrams;

        string anagram = "";
        for(string str : strs){
            anagram = str; 
            sort(anagram.begin(), anagram.end());
            anagrams[anagram].push_back(str);
        }

        vector<vector<string>> solution;
        for (const auto& pair : anagrams) solution.push_back(pair.second);
        return solution;

    }
};
