#include "../include/niu_ke.h"

#include <iostream>
namespace niu_ke {

ListNode *ListOperation::ReverseList(ListNode *pHead) {
  if (!pHead) {
    return nullptr;
  }
  if (!pHead->next) {
    return pHead;
  }
  ListNode *cur = nullptr;
  ListNode *next = pHead;
  while (next) {
    ListNode *temp = next->next;
    next->next = cur;
    cur = next;
    next = temp;
    temp = nullptr;
  }
  return cur;
}

ListNode *ListOperation::CreatListByArray(std::vector<int> arr) {
  if (arr.empty()) {
    return nullptr;
  }
  ListNode *head = new ListNode(0);
  ListNode *cur = head;
  for (auto temp = arr.cbegin(); temp != arr.cend(); ++temp) {
    ListNode *node = new ListNode(*temp);
    cur->next = node;
    cur = cur->next;
    node = nullptr;
  }
  return head->next;
}

void ListOperation::ListPrint(ListNode *pHead) {
  ListNode *cur = pHead;
  while (cur) {
    std::cout << cur->val << ";";
    cur = cur->next;
  }
  std::cout << "endl" << std::endl;
}

void ListOperation::ListDestory(ListNode *pHead) {
  ListNode *cur = pHead;
  while (cur) {
    ListNode *temp = cur->next;
    cur->next = nullptr;
    delete cur;
    cur = temp;
  }
}

ListNode *ListOperation::reverseBetween(ListNode *head, int m, int n) {
  if (!head) {
    return nullptr;
  }
  if (m == n) {
    return head;
  }
  ListNode *phead = new ListNode(0, head);
  ListNode *pre = phead;
  ListNode *cur = head;
  ListNode *next = cur->next;
  ListNode *node_m = nullptr;
  ListNode *m_pre = nullptr;
  int node_num = 1;
  while (cur) {
    if (node_num <= m) {
      if (node_num == m) {
        m_pre = pre;
        node_m = cur;
        cur->next = nullptr;
      }
      pre = cur;
      cur = next;
      next = next->next;
    } else if (node_num > m && node_num <= n) {
      cur->next = pre;
      if (node_num == n) {
        m_pre->next = cur;
        node_m->next = next;
        break;
      }
      pre = cur;
      cur = next;
      next = next->next;
    }
    node_num++;
  }
  return phead->next;
}
ListNode *ListOperation::addInList(ListNode *head1, ListNode *head2) {
  // define 2 string to stroe the value of list
  // std::string str1;
  // std::string str2;
  // ListNode *cur = head1;
  // while(cur) {
  //     str1.insert(str1.size(), std::to_string(cur->val));
  //     cur = cur->next;
  // }
  // cur = head2;
  // while(cur) {
  //     str2.insert(str2.size(), std::to_string(cur->val));
  //     cur = cur->next;
  // }
  // if (str1.empty() && str2.empty()) return nullptr;
  // unsigned long long val1 = str1.empty() ? 0 : std::stol(str1);
  // unsigned long long val2 = str2.empty() ? 0 : std::stol(str2);
  // std::string res_str = std::to_string(val1+val2);
  // ListNode *res = new ListNode(-1);
  // cur = res;
  // for(int i=0; i < res_str.size(); ++i) {
  //     char temp = res_str[i];
  //     ListNode *temp_node = new ListNode(std::stoi(&temp));
  //     cur->next = temp_node;
  //     cur = cur->next;
  // }
  // return res->next;
  // reverse list1
  ListNode *cur1 = head1;
  ListNode *next = head1 ? cur1->next : nullptr;
  cur1->next = nullptr;
  while (next) {
    ListNode *next_next = next->next;
    next->next = cur1;
    cur1 = next;
    next = next_next;
  }
  ListNode *cur2 = head2;
  next = head2 ? cur2->next : nullptr;
  cur2->next = nullptr;
  while (next) {
    ListNode *next_next = next->next;
    next->next = cur2;
    cur2 = next;
    next = next_next;
  }
  int temp = 0;
  ListNode *res = new ListNode(-1);
  ListNode *cur = res;
  while (cur1 || cur2) {
    int val1 = cur1 ? cur1->val : 0;
    int val2 = cur2 ? cur2->val : 0;
    int sum = val1 + val2 + temp;
    int val = sum % 10;
    temp = sum / 10;
    ListNode *temp_node = new ListNode(val);
    cur->next = temp_node;
    cur = cur->next;
    cur1 = cur1 ? cur1->next : nullptr;
    cur2 = cur2 ? cur2->next : nullptr;
  }
  if (temp != 0) {
    ListNode *temp_node = new ListNode(temp);
    cur->next = temp_node;
    cur = cur->next;
  }
  cur = res->next;
  next = cur ? cur->next : nullptr;
  cur->next = nullptr;
  while (next) {
    ListNode *next_next = next->next;
    next->next = cur;
    cur = next;
    next = next_next;
  }
  return cur;
}
ListNode *ListOperation::sortInList(ListNode *head) {
  std::vector<int> vec;
  while (head) {
    vec.push_back(head->val);
    head = head->next;
  }
  if (vec.empty()) return nullptr;
  std::sort(vec.begin(), vec.end());
  ListNode *res = new ListNode(-1);
  ListNode *cur = res;
  for (int i = 0; i < vec.size(); ++i) {
    ListNode *temp = new ListNode(vec[i]);
    cur->next = temp;
    cur = cur->next;
  }
  return res->next;
}
ListNode *ListOperation::oddEvenList(ListNode *head) {
  // std::vector<int> vec1;
  // std::vector<int> vec2;
  // int node_index = 0;
  // while(head) {
  //     ++node_index;
  //     if(node_index % 2 != 0) {
  //         vec1.push_back(head->val);
  //     } else {
  //         vec2.push_back(head->val);
  //     }
  //     head = head->next;
  // }
  // ListNode *res = new ListNode(-1);
  // ListNode *cur = res;
  // for(int i=0; i<vec1.size(); ++i) {
  //     ListNode *temp = new ListNode(vec1[i]);
  //     cur->next = temp;
  //     cur = cur->next;
  // }
  // for(int i=0; i<vec2.size(); ++i) {
  //     ListNode *temp = new ListNode(vec2[i]);
  //     cur->next = temp;
  //     cur = cur->next;
  // }
  // return res->next;
  ListNode *res1 = new ListNode(-1);
  ListNode *cur1 = res1;
  ListNode *res2 = new ListNode(-1);
  ListNode *cur2 = res2;
  int node_index = 0;
  while (head) {
    ListNode *next = head->next;
    ++node_index;
    if (node_index % 2 != 0) {
      cur1->next = head;
      cur1 = cur1->next;
      cur1->next = nullptr;
    } else {
      cur2->next = head;
      cur2 = cur2->next;
      cur2->next = nullptr;
    }
    head = next;
  }
  cur1->next = res2->next;
  return res1->next;
}
int BinarySearch::search(std::vector<int> &nums, int target) {
  int left = 0;
  int right = nums.size() - 1;
  while (left <= right) {
    int mid = (left + right) / 2;
    if (nums[mid] == target) {
      return mid;
    } else {
      if (nums[mid] > target) {
        right = mid - 1;
      } else {
        left = mid + 1;
      }
    }
  }
  return -1;
}
int BinarySearch::findPeakElement(std::vector<int> &nums) {
  int left = 0;
  int right = nums.size() - 1;
  while (left < right) {
    int mid = (left + right) / 2;
    if (nums[mid] > nums[mid + 1]) {
      right = mid;
    } else {
      left = mid + 1;
    }
  }
  return right;
}

bool BinarySearch::Find(int target, std::vector<std::vector<int> > array) {
    // if (array.empty()) return false;
    // for (auto it : array) {
    //     if(it.front() <= target && it.back() >= target ) {
    //         int left = 0, right = it.size() - 1;
    //         while (left <= right) {
    //             int mid = left + ((right - left)>>1);
    //             if(it[mid] == target) {
    //                 return true;
    //             } else {
    //                 if(it[mid] > target) {
    //                     right = mid -1;
    //                 } else {
    //                     left = mid + 1;
    //                 }
    //             }
    //         }
    //     }
    // }
    // return false;
    int row = array.size()-1, col = 0;
    if(!(array.empty() && array[0].empty())) return false;
    while (row >= 0 && col <= array[0].size()-1) {
        int temp = array.at(row).at(col);
        if (temp == target)
            return true;
        else if(temp > target)
            --row;
        else
            ++col;
    }
    return false;
}

void SortMethod::SelectionSort(std::vector<int> &nums) {
  if (nums.size() < 2) return;
  for (int i = 0; i < nums.size() - 1; ++i) {
    int min_index = i;
    for (int j = i + 1; j < nums.size(); ++j) {
      min_index = nums[j] < nums[min_index] ? j : min_index;
    }
    if (min_index == i) continue;
    int temp = nums[i];
    nums[i] = nums[min_index];
    nums[min_index] = temp;
  }
}

void SortMethod::MpSort(std::vector<int> &nums) {
  for (int i = nums.size() - 1; i > 0; --i) {
    for (int j = 0; j < i; ++j) {
      if (nums[j] > nums[j + 1]) swap(nums, j, j + 1);
    }
  }
}

void SortMethod::InsertSort(std::vector<int> &nums) {
  for (int i = 1; i < nums.size(); ++i) {
    for (int j = i-1; j >= 0 && nums[j] > nums[j+1]; --j)
        swap(nums,j,j+1);
  }
}

void SortMethod::swap(std::vector<int> &nums, int i, int j) {
  int temp = nums[i];
  nums[i] = nums[j];
  nums[j] = temp;
}
}