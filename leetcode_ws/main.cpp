// Copyright 2022 livie
#include <iostream>

#include "include/leet_code.h"
using leetcode_study::LeetCode;
using leetcode_study::ListOperation;
LeetCode leetCode;
ListOperation list_temp;
void test_twoSum() {
  std::vector<int> numbers = {0, 1, 2, 5, 6};
  std::vector<int> res = leetCode.twoSum(numbers, 3);
}
void test_reverseString() {
  std::vector<char> s = {'h', 'e', 'l', 'l', 'o'};
  leetCode.reverseString(s);
  // leetCode.lengthOfLongestSubstring("abcaefb");
  leetCode.lengthOfLongestSubstring("abba");
  leetCode.checkInclusion("ab", "a");
}
void TestsortedSquaresnew() {
  std::vector<int> nums = {-10000, -9999, -7, -5, 0, 0, 10000};
  leetCode.sortedSquares(nums);
}

void Testrotate() {
  std::vector<int> nums = {1, 5, 6, 8, 10, 7};
  leetCode.rotate(nums, 2);
}
// int main()
void TestsortedSquares() {
  std::vector<int> nums = {-4, -1, 0, 3, 10};
  leetCode.sortedSquaresnew(nums);
}

void TestMidNode() {
  std::vector<int> nums{2, 5, 6, 3};
  auto head = leetCode.transforArray2List(nums);
  leetCode.deleteList(head);
  list_temp.CreatListByArray(nums);
  list_temp.GetMidNode();
  list_temp.ClearList();
}

void TestDeleteNthNode() {
  std::vector<int> nums{2, 5};
  auto head = leetCode.transforArray2List(nums);
  auto temp = list_temp.removeNthFromEnd(head,2);
}

void TestaddInList() {
  std::vector<int> nums{9,3,7};
  auto head1 = leetCode.transforArray2List(nums);
  std::vector<int> nums1{6,3};
  auto head2 = leetCode.transforArray2List(nums1);
  auto res = list_temp.addInList(head1,head2);
}

void TestReverseList() {

  std::vector<int> nums{2, 5,6,8,7};
  auto head1 = leetCode.transforArray2List(nums);
  auto head2 = list_temp.reverseList(head1);
}
void TestDeleteRepeateEle() {

  std::vector<int> nums{1,1,1,2,3,3,5,5,6,8,7};
  auto head1 = leetCode.transforArray2List(nums);
  auto head2 = list_temp.deleteDuplicates(head1);
}
int main(int argc, char *argv[]) {
//   test_twoSum();
//   test_reverseString();
//   TestsortedSquares();
//   Testrotate();
//   TestsortedSquaresnew();
//   TestMidNode();
    // TestDeleteNthNode();
    // TestaddInList();
    TestDeleteRepeateEle();
    // TestReverseList();
  std::cout << "come on livie" << std::endl;
  return 0;
}
