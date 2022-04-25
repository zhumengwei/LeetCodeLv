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

int main(int argc, char *argv[]) {
  test_twoSum();
  test_reverseString();
  TestsortedSquares();
  Testrotate();
  TestsortedSquaresnew();
  TestMidNode();
  std::cout << "come on livie" << std::endl;
  return 0;
}
