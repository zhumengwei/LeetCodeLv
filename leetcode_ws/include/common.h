#ifndef __COMMON_H__
#define __COMMON_H__

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct TreeNode {
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) { ; }
};

struct Node {
    std::string type;
    int val;
};

#endif