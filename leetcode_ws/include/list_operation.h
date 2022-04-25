// Copyright 2022 livie
#pragma once
#include <vector>

using std::vector;
namespace leetcode_study {

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    explicit ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class ListOperation {
 public:
    ListOperation();
    ~ListOperation();
    void CreatListByArray(const vector<int>& nums);
    void ClearList();
    void PrintListNode();
    ListNode* GetMidNode();
 private:
    ListNode *head_;
    int node_num_;
};

}  // namespace leetcode_study
