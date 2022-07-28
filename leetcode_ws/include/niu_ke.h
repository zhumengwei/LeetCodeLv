#ifndef __NIU_KE_H__
#define __NIU_KE_H__
#include <algorithm>
#include <cmath>
#include <string>
#include <unordered_map>
#include <vector>

#include "common.h"
namespace niu_ke {

class ListOperation {
 public:
  ListOperation() { ; }
  ~ListOperation() { ; }
  ListNode* ReverseList(ListNode* pHead);
  ListNode* CreatListByArray(std::vector<int> arr);
  void ListPrint(ListNode* pHead);
  void ListDestory(ListNode* pHead);
  ListNode* reverseBetween(ListNode* head, int m, int n);
  ListNode* addInList(ListNode* head1, ListNode* head2);
  ListNode* sortInList(ListNode* head);
  ListNode* oddEvenList(ListNode* head);
};

class BinarySearch {
 public:
  int search(std::vector<int>& nums, int target);
  int findPeakElement(std::vector<int>& nums);
  bool Find(int target, std::vector<std::vector<int> > array);
};

class SortMethod {
 public:
  void SelectionSort(std::vector<int>& nums);
  void MpSort(std::vector<int>& nums);
  void InsertSort(std::vector<int>& nums);

 private:
  void swap(std::vector<int>& nums, int i, int j);
};

class Tree {
 public:
  Tree();
  ~Tree();
  std::vector<int> inorderTraversal(TreeNode* root);
  TreeNode* CreateTree(std::vector<std::vector<Node>>& node_nums);
 private:
  
  
};

}

#endif