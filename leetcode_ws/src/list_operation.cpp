// Copyright 2022 livie
#include "include/list_operation.h"

#include <iostream>

namespace leetcode_study {
ListOperation::ListOperation():head_(nullptr), node_num_(0) {}

ListOperation::~ListOperation() {
    head_ = nullptr;
}

void ListOperation::CreatListByArray(const vector<int>& nums) {
  if (nums.empty()) {
      std::cout << "no node to creat" << std::endl;
      return;
  }
  int index = 0;
  ListNode *cur_node = nullptr;
  while (index < nums.size()) {
      if (!head_) {
          head_ = new ListNode(nums[index]);
          cur_node = head_;
      } else {
          cur_node->next = new ListNode(nums[index]);
          cur_node = cur_node->next;
      }
      index++;
  }
}

void ListOperation::ClearList() {
  if (!head_) {
      std::cout << "empty list" << std::endl;
      return;
  }
  if (!head_->next) {
      delete head_;
      head_ = nullptr;
      return;
  }
  while (head_->next) {
      ListNode *next_node = head_->next;
      head_->next = head_->next->next;
      delete next_node;
      next_node = nullptr;
  }
  delete head_;
  head_ = nullptr;
  return;
}
void ListOperation::PrintListNode() {
  if (!head_) {
      std::cout << "empty list" << std::endl;
      return;
  }
  ListNode *cur_node = head_;
  int node_index = 0;
  while (cur_node) {
      std::cout << "node-" << node_index << ":" << cur_node->val;
      cur_node = cur_node->next;
      node_index++;
  }
}
ListNode* ListOperation::GetMidNode() {
    if (!head_) {
        std::cout << "empty list" << std::endl;
        return nullptr;
    }
    ListNode *cur_node = head_;
    std::vector<ListNode*> vec_addreess;
    int node_num = 0;
    while (cur_node) {
        vec_addreess.push_back(cur_node);
        node_num++;
        cur_node = cur_node->next;
    }
    return vec_addreess[node_num/2];
}
}  // namespace leetcode_study
