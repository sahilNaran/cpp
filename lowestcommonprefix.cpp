#include <iostream>
#include <string>
#include <vector>
class Solution {
public:
  std::string longestCommonPrefix(std::vector<std::string> &strs) {
    if (strs.empty()) {
      return "";
    }

    for (int i = 0; i < strs[0].length(); i++) {
      char current = strs[0][i];
      for (int j = 1; j < strs.size(); j++) {
        if (i >= strs[j].length() || strs[j][i] != current) {
          return strs[0].substr(0, i);
        }
      }
    }
    return strs[0];
  }
};

int main() {
  Solution solution;
  std::vector<std::string> input = {"flower", "flow", "flight"};
  std::cout << solution.longestCommonPrefix(input) << std::endl;
}

//
// Write a function to find the longest common prefix string amongst an array of
// strings.
//
// If there is no common prefix, return an empty string "".
//
//
//
// Example 1:
//
// Input: strs = ["flower","flow","flight"]
// Output: "fl"
// Example 2:
//
// Input: strs = ["dog","racecar","car"]
// Output: ""
// Explanation: There is no common prefix among the input strings.
