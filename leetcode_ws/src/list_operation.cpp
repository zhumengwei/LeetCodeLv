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

// ListNode *ListOperation::Merge(ListNode *pHead1, ListNode *pHead2) {
//   ListNode *res = new ListNode(-1);
//   ListNode *cur = res;
//   while (pHead1 && pHead2) {
//     if (pHead1->val <= pHead2->val) {
//       cur->next = pHead1;
//       pHead1 = pHead1->next;
//     } else {
//       cur->next = pHead2;
//       pHead2 = pHead2->next;
//     }
//     cur = cur->next;
//   }
//   if (pHead1) {
//     cur->next = pHead1;
//   } else {
//     cur->next = pHead2;
//   }
//   return res->next;
// }
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
  ListNode *res = new ListNode(-1);
  res->next = head;
  ListNode *pre = res;
  ListNode *tail = res;
  for (int i = 1; i <= n; i++) {
    tail = tail->next;
  }
  while (tail->next) {
    pre = pre->next;
    tail = tail->next;
  }
  ListNode *del_node = pre->next;
  pre->next = del_node->next;
  delete del_node;
  return res->next;
}

ListNode* ListOperation::reverseList(ListNode* head) {
    if (!head) {
        return nullptr;
    }
    ListNode *pre = nullptr;
    ListNode *cur = head;
    ListNode *next = nullptr;
    while (cur) {
        next = cur->next;
        cur->next = pre;
        pre = cur;
        cur = next;
    }
    return pre;
}
ListNode* ListOperation::addInList(ListNode* head1, ListNode* head2) {
    ListNode *head1_new = reverseList(head1);
    ListNode *head2_new = reverseList(head2);
    ListNode *res = new  ListNode(-1);
    ListNode *cur = res;
    int val = 0;
    ListNode *cur1 = head1_new;
    ListNode *cur2 = head2_new;
    while (cur1 || cur2) {
        int val1 = cur1 ? cur1->val : 0;
        int val2 = cur2 ? cur2->val : 0;
        int temp = val1 + val2 + val;
        val = temp / 10;
        temp %= 10;
        ListNode *node = new ListNode(temp);
        cur->next = node;
        cur = cur->next;
        cur1 = cur1 ? cur1->next : nullptr;
        cur2 = cur2 ? cur2->next : nullptr;
    }
    if (val != 0) {
        ListNode *node = new ListNode(val);
        cur->next = node;
    }
    res->next = reverseList(res->next);
    return res->next;
    // std::vector<int> vec1;
    // int num1 = 0,num2 = 0;
    // while (head1) {
    //     vec1.push_back(head1->val);
    //     head1 = head1->next;
    //     num1++;
    // }
    // std::vector<int> vec2;
    // while (head2) {
    //     vec2.push_back(head2->val);
    //     head2 = head2->next;
    //     num2++;
    // }
    // if (num1 > num2) {
    //     for(int i=0;i < num1-num2;i++) {
    //         vec2.insert(vec2.begin(),0);
    //     }
    // } else if (num1 < num2) {
    //     for (int i= 0;i<num2-num1;i++) {
    //         vec1.insert(vec1.begin(),0);
    //     }
    // }
    // std::vector<int> vec_temp(vec1.size(),0);
    // int val =0;
    // for (int i = vec_temp.size()-1;i>=0;i--) {
    //    int val_temp = vec1[i] + vec2[i] + val;
    //    val = val_temp / 10;
    //    val_temp %= 10;
    //    vec_temp[i] = val_temp;
    // }
    // if (val != 0) {
    //     vec_temp.insert(vec_temp.begin(),val);
    // }
    // ListNode *res = new ListNode(-1);
    // ListNode *cur = res;
    // for (int i = 0;i<vec_temp.size();i++) {
    //     ListNode *temp = new ListNode(vec_temp[i]);
    //     cur->next = temp;
    //     cur = cur->next;
    // }
    // return res->next;
}
ListNode* ListOperation::sortInList(ListNode* head) {
    ListNode *cur = head;
    std::vector<int> vec;
    while(cur) {
        vec.push_back(cur->val);
        cur = cur->next;
    }
    if (vec.size() == 0) {
        return nullptr;
    }
    std::sort(vec.begin(), vec.end());
    ListNode *res = new ListNode(-1);
    cur = res;
    for (int i=0; i<vec.size();i++) {
        ListNode *temp = new ListNode(vec[i]);
        cur->next = temp;
        cur = cur->next;
    }
    return res->next;
}
ListNode* ListOperation::deleteDuplicates(ListNode* head) {
   ListNode *cur = head;
   while(cur) {
       if (!cur->next) {
           cur=cur->next;
       } else {
        if (cur->val == cur->next->val) {
            ListNode *next = cur->next;
            cur->next = next->next;
            delete next;
            next = nullptr;
            continue;
        }
        cur = cur->next;
       }
    }
    return head;
   } 
}  // namespace leetcode_study
