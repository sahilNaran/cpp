#include <iostream>
#include <ostream>
class Solution {
public:
  bool isPalindrome(int x) {
    if (x < 0) {
      return false;
    }
    int64_t workingNumber = x;
    int64_t reversedNumber = 0;

    while (workingNumber > 0) {
      int lastDigit = workingNumber % 10;
      reversedNumber = reversedNumber * 10 + lastDigit;
      workingNumber = workingNumber / 10;
    }
    return x == reversedNumber;
  }
};

int main() {
  Solution solution;

  std::cout << solution.isPalindrome(121) << std::endl;
  std::cout << solution.isPalindrome(-121) << std::endl;
  std::cout << solution.isPalindrome(10) << std::endl;
  std::cout << solution.isPalindrome(1234567899) << std::endl;
}

//
// Example 1:
//
// Input: x = 121
// Output: true
// Explanation: 121 reads as 121 from left to right and from right to left.
// Example 2:
//
// Input: x = -121
// Output: false
// Explanation: From left to right, it reads -121. From right to left, it
// becomes 121-. Therefore it is not a palindrome. Example 3:
//
// Input: x = 10
// Output: false
// Explanation: Reads 01 from right to left. Therefore it is not a palindrome.
