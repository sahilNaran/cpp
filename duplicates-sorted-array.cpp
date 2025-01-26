#include <iostream>
#include <set>
#include <vector>
class Solution {
public:
  int removeDuplicates(std::vector<int> &nums) {
    std::set<int> noDupes(nums.begin(), nums.end());
    nums = std::vector<int>(noDupes.begin(), noDupes.end());
    return noDupes.size();
  }
};

int main() {
  Solution solution;

  std::vector<int> testNumbers = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
  std::cout << solution.removeDuplicates(testNumbers);
}

//
// Input: nums = [0,0,1,1,1,2,2,3,3,4]
// Output: 5, nums = [0,1,2,3,4,_,_,_,_,_]
// Explanation: Your function should return k = 5, with the first five elements
// of nums being 0, 1, 2, 3, and 4 respectively. It does not matter what you
// leave beyond the returned k (hence they are underscores).
