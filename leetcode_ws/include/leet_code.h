// Copyright 2022 livie
#pragma once
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <cmath>

#include "include/list_operation.h"

typedef std::unordered_map<char, int> MyMap;

namespace leetcode_study {

class LeetCode{
 public:
    LeetCode() {}
    ~LeetCode() {}
    std::vector<int> twoSum(std::vector<int>& numbers, int target);
    void reverseString(std::vector<char>& s);
    std::string reverseWords(std::string s);
    int lengthOfLongestSubstring(std::string s);
    bool checkInclusion(std::string s1, std::string s2);
    std::vector<int> sortedSquares(const std::vector<int>& nums);
    void rotate(std::vector<int>& nums, int k);
    std::vector<int> sortedSquaresnew(std::vector<int>& nums);
    ListNode* transforArray2List(const std::vector<int>& nums);
    ListNode* middleNode(ListNode* head);
    void deleteList(ListNode* head);
};
}  // namespace leetcode_study
