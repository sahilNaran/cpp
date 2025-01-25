#include <iostream>
#include <ostream>
#include <string>
class Solution {
public:
  int romanToInt(std::string s) {
    std::unordered_map<char, int> lookup;
    lookup['I'] = 1;
    lookup['V'] = 5;
    lookup['X'] = 10;
    lookup['L'] = 50;
    lookup['C'] = 100;
    lookup['D'] = 500;
    lookup['M'] = 1000;

    int sum = 0;

    for (int i = 0; i < s.length(); i++) {
      int lookupValue = lookup[s[i]];
      if (lookupValue < lookup[s[i + 1]]) {
        sum -= lookupValue;
      } else {
        sum += lookupValue;
      }
    }
    return sum;
  }
};

int main() {
  Solution solution;
  std::cout << solution.romanToInt("III") << std::endl;
  std::cout << solution.romanToInt("LVIII") << std::endl;
  std::cout << solution.romanToInt("MCMXCIV") << std::endl;
}

//
//     int num = 0;
//     int length = s.length();
//     for (int i = 0; i < length; i++) {
//       if (s[i] == 'M') {
//         num += 1000;
//       }
//       if (s[i] == 'D') {
//         num += 500;
//       }
//       if (s[i] == 'C' && i + 1 < length &&
//           (s[i + 1] == 'M' || s[i + 1] == 'D')) {
//         num -= 100;
//       } else if (s[i] == 'C') {
//         num += 100;
//       }
//       if (s[i] == 'L') {
//         num += 50;
//       }
//       if (s[i] == 'X' && i + 1 < length &&
//           (s[i + 1] == 'L' || s[i + 1] == 'C')) {
//         num -= 10;
//       } else if (s[i] == 'X') {
//         num += 10;
//       }
//       if (s[i] == 'V') {
//         num += 5;
//       }
//       if (s[i] == 'I' && i + 1 < length &&
//           (s[i + 1] == 'X' || s[i + 1] == 'V')) {
//         num -= 1;
//       } else if (s[i] == 'I') {
//         num += 1;
//       }
//     }
//     return num;
//
// // Roman numerals are represented by seven different symbols: I, V, X, L, C,
// D
// // and M.
// //
// // Symbol       Value
// // I             1
// // V             5
// // X             10
// // L             50
// // C             100
// // D             500
// // M             1000
// // For example, 2 is written as II in Roman numeral, just two ones added
// // together. 12 is written as XII, which is simply X + II. The number 27 is
// // written as XXVII, which is XX + V + II.
// //
// // Roman numerals are usually written largest to smallest from left to right.
// // However, the numeral for four is not IIII. Instead, the number four is
// // written as IV. Because the one is before the five we subtract it making
// // four. The same principle applies to the number nine, which is written as
// // IX. There are six instances where subtraction is used:
// //
// // I can be placed before V (5) and X (10) to make 4 and 9.
// // X can be placed before L (50) and C (100) to make 40 and 90.
// // C can be placed before D (500) and M (1000) to make 400 and 900.
// // Given a roman numeral, convert it to an integer.
// //
// //
// //
// // Example 1:
// //
// // Input: s = "III"
// // Output: 3
// // Explanation: III = 3.
// // Example 2:
// //
// // Input: s = "LVIII"
// // Output: 58
// // Explanation: L = 50, V= 5, III = 3.
// // Example 3:
// //
// // Input: s = "MCMXCIV"
// // Output: 1994
// // Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
// //
// //
// // Constraints:
// //
// // 1 <= s.length <= 15
// // s contains only the characters ('I', 'V', 'X', 'L', 'C', 'D', 'M').
// // It is guaranteed that s is a valid roman numeral in the range [1, 3999].
