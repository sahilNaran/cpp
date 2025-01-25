#include <iostream>
#include <ostream>
#include <stack>
#include <string>
class Solution {
public:
  bool isValid(std::string s) {
    std::stack<char> pringles;

    for (char pringle : s) {
      if (pringle == '(' || pringle == '[' || pringle == '{') {
        pringles.push(pringle);
      } else {
        if (pringles.empty()) {
          return false;
        }
        char top = pringles.top();
        if ((pringle == ')' && top == '(') || (pringle == ']' && top == '[') ||
            (pringle == '}' && top == '{')) {
          pringles.pop();
        } else {
          return false;
        }
      }
    }
    return pringles.empty();
  }
};

int main() {
  Solution solution;

  std::cout << solution.isValid("()") << std::endl;
  std::cout << solution.isValid("(){}[]") << std::endl;
  std::cout << solution.isValid("(]") << std::endl;
  std::cout << solution.isValid("([])") << std::endl;
}

//
// Given a string s containing just the characters '(', ')', '{', '}', '[' and
// ']', determine if the input string is valid.
//
// An input string is valid if:
//
// Open brackets must be closed by the same type of brackets.
// Open brackets must be closed in the correct order.
// Every close bracket has a corresponding open bracket of the same type.
//
//
// Example 1:
//
// Input: s = "()"
//
// Output: true
//
// Example 2:
//
// Input: s = "()[]{}"
//
// Output: true
//
// Example 3:
//
// Input: s = "(]"
//
// Output: false
//
// Example 4:
//
// Input: s = "([])"
//
// Output: true
//
//
