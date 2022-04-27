// Copyright 2022 livie
#include "include/list_operation.h"

#include <iostream>

namespace leetcode_study {
ListOperation::ListOperation() : head_(nullptr), node_num_(0) {}

ListOperation::~ListOperation() { head_ = nullptr; }

void ListOperation::CreatListByArray(const vector<int> &nums) {
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
ListNode *ListOperation::GetMidNode() {
  if (!head_) {
    std::cout << "empty list" << std::endl;
    return nullptr;
  }
  ListNode *cur_node = head_;
  std::vector<ListNode *> vec_addreess;
  int node_num = 0;
  while (cur_node) {
    vec_addreess.push_back(cur_node);
    node_num++;
    cur_node = cur_node->next;
  }
  return vec_addreess[node_num / 2];
}
ListNode *ListOperation::Merge(ListNode *pHead1, ListNode *pHead2) {
  ListNode *res = new ListNode(-1);
  ListNode *cur = res;
  while (pHead1 && pHead2) {
    if (pHead1->val <= pHead2->val) {
      cur->next = pHead1;
      pHead1 = pHead1->next;
    } else {
      cur->next = pHead2;
      pHead2 = pHead2->next;
    }
    cur = cur->next;
  }
  if (pHead1) {
    cur->next = pHead1;
  } else {
    cur->next = pHead2;
  }
  return res->next;
}
ListNode *ListOperation::mergeKLists(vector<ListNode *> &lists) {
  // std::vector<int> vec_node_val;
  // for (int i= 0; i< lists.size(); i++) {
  //     ListNode *cur = lists[i];
  //     while (cur) {
  //         vec_node_val.push_back(cur->val);
  //         cur = cur->next;
  //     }
  // }
  // std::sort(vec_node_val.begin(), vec_node_val.end());
  // ListNode *res = new ListNode(-1);
  // ListNode *cur = res;
  // for (int i= 0; i< vec_node_val.size(); i++) {
  //     ListNode *temp = new ListNode(vec_node_val[i]);
  //     cur->next = temp;
  //     cur = cur->next;
  // }
  // return res->next;
  if (lists.empty()) {
    return nullptr;
  } else if (lists.size() == 1) {
    return lists[0];
  } else {
    vector<ListNode *> mid_lists;
    for (int i = 0; i < lists.size(); i++) {
      if ((i + 1) % 2 == 0) {
        ListNode *temp = Merge(lists[i - 1], lists[i]);
        mid_lists.push_back(temp);
      } else if (i == lists.size() - 1) {
        mid_lists.push_back(lists[i]);
      }
    }
    return mergeKLists(mid_lists);
  }
}

ListNode *ListOperation::Merge(ListNode *pHead1, ListNode *pHead2) {
  ListNode *res = new ListNode(-1);
  ListNode *cur = res;
  while (pHead1 && pHead2) {
    if (pHead1->val <= pHead2->val) {
      cur->next = pHead1;
      pHead1 = pHead1->next;
    } else {
      cur->next = pHead2;
      pHead2 = pHead2->next;
    }
    cur = cur->next;
  }
  if (pHead1) {
    cur->next = pHead1;
  } else {
    cur->next = pHead2;
  }
  return res->next;
}
ListNode *ListOperation::FindKthToTail(ListNode *pHead, int k) {
  if (!pHead || k == 0) {
    return nullptr;
  }
  ListNode *pre = pHead;
  ListNode *tail = pre;
  for (int i = 1; i < k; i++) {
    tail = tail->next;
    if (!tail) {
      return nullptr;
    }
  }
  while (tail->next) {
    tail = tail->next;
    pre = pre->next;
  }
  return pre;
}

ListNode *ListOperation::removeNthFromEnd(ListNode *head, int n) {
  ListNode *pre = new ListNode(-1);
  pre->next = head;
  ListNode *tail = pre;
  for (int i = 1; i <= n; i++) {
    tail = tail->next;
  }
  while (tail->next) {
    pre = pre->next;
    tail = tail->next;
  }
}
}  // namespace leetcode_study
