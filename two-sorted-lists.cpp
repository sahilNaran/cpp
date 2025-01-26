
#include <iostream>
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
    ListNode *placeHolder = new ListNode();
    ListNode *current = placeHolder;

    while (list1 || list2) {
      if (!list2 || (list1 && list1->val < list2->val)) {
        current->next = new ListNode(list1->val);
        list1 = list1->next;
      } else {
        current->next = new ListNode(list2->val);
        list2 = list2->next;
      }
      current = current->next;
    }

    ListNode *merged = placeHolder->next;
    delete placeHolder;
    return merged;
  }
};

int main() {
  Solution s;

  ListNode *l1 = new ListNode(1);
  l1->next = new ListNode(2);
  l1->next->next = new ListNode(4);

  ListNode *l2 = new ListNode(1);
  l2->next = new ListNode(3);
  l2->next->next = new ListNode(4);

  std::cout << "Test 1: ";
  ListNode *result = s.mergeTwoLists(l1, l2);
  while (result != nullptr) {
    std::cout << result->val << " ";
    result = result->next;
  }
  std::cout << "\n";

  std::cout << "Test 2: ";
  result = s.mergeTwoLists(nullptr, nullptr);
  while (result != nullptr) {
    std::cout << result->val << " ";
    result = result->next;
  }
  std::cout << "\n";

  std::cout << "Test 3: ";
  ListNode *l3 = new ListNode(0);
  result = s.mergeTwoLists(nullptr, l3);
  while (result != nullptr) {
    std::cout << result->val << " ";
    result = result->next;
  }
  std::cout << "\n";

  return 0;
}

//
// Input: list1 = [1,2,4], list2 = [1,3,4]
// Output: [1,1,2,3,4,4]
// Example 2:
//
// Input: list1 = [], list2 = []
// Output: []
// Example 3:
//
// Input: list1 = [], list2 = [0]
// Output: [0]
