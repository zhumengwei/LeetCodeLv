#include "include/leet_code.h"
#include "include/niu_ke.h"
#include <iostream>

#include "include/list_operation.h"
using leetcode_study::LeetCode;
using leetcode_study::ListOperation;
LeetCode leetCode;
using namespace niu_ke;
void test_twoSum()
{
    
    std::vector<int> numbers = {0,1,2,5,6};
    std::vector<int> res = leetCode.twoSum(numbers,3);
}
void test_reverseString()
{
    std::vector<char> s = {'h','e','l','l','o'};
    leetCode.reverseString(s);
    //leetCode.lengthOfLongestSubstring("abcaefb");
    leetCode.lengthOfLongestSubstring("abba");
    leetCode.checkInclusion("ab","a");
}
void TestsortedSquaresnew()
{
    std::vector<int> nums = {-10000,-9999,-7,-5,0,0,10000};
    leetCode.sortedSquares(nums);
}

void Testrotate()
{
    std::vector<int> nums = {1,5,6,8,10,7};
    leetCode.rotate(nums,2);
}
// int main()
void TestsortedSquares() {
    std::vector<int> nums = {-4,-1,0,3,10};
    leetCode.sortedSquaresnew(nums);
}
void NiuKeTest1() {
    niu_ke::ListOperation list_test;
    std::vector<int> arr{2,5,6,7,9,10,11};
    ListNode* temp = list_test.CreatListByArray(arr);
    // ListNode* res = list_test.ReverseList(temp);
    // list_test.ListPrint(res);
    list_test.reverseBetween(temp,3,6);
    list_test.ListDestory(temp);
}
void NiuKeTest2() {
    // two value sum
    niu_ke::ListOperation list_test;
    // std::vector<int> arr1{5,9,7,5,7,1,2,6,4,2,7,8,9,6,1,6,6,1,1,4,2,9,5,5,0,4,6,3,0,4,3,5,6,7,0,5,5,4,4,0};
    // std::vector<int> arr2{1,3,2,5,0,6,0,2,1,4,3,9,3,0,9,9,0,3,1,6,5,7,8,6,2,3,8,5,0,9,7,9,4,5,9,9,4,9,3,6};
    std::vector<int> arr1{9,3,7};
    std::vector<int> arr2{6,3};
    ListNode* temp1 = list_test.CreatListByArray(arr1);
    ListNode* temp2 = list_test.CreatListByArray(arr2);
    // ListNode* res = list_test.ReverseList(temp);
    // list_test.ListPrint(res);
    list_test.addInList(temp1, temp2);
    list_test.ListDestory(temp1);
    list_test.ListDestory(temp2);
}

void NiuKeTest3() {
    niu_ke::ListOperation list_test;
    std::vector<int> arr{1,3,2,4,5};
    ListNode* temp = list_test.CreatListByArray(arr);
    list_test.sortInList(temp);
    list_test.ListDestory(temp);
}

void NiuKeTest4() {
    niu_ke::ListOperation list_test;
    std::vector<int> arr{1,2,3,4,5};
    ListNode* temp = list_test.CreatListByArray(arr);
    list_test.oddEvenList(temp);
    list_test.ListDestory(temp);
}

void BinarySearchTest1() {
    niu_ke::BinarySearch binary_search;
    std::vector<int> temp = {2,4,1,2,7,8,4};
    int index =binary_search.findPeakElement(temp);
}

void BinarySearchTest2() {
    niu_ke::BinarySearch binary_search;
    // std::vector<std::vector<int> > temp = {{1,2,8,9},{2,4,9,12},{4,7,10,13},{6,8,11,15}};
    std::vector<std::vector<int> > temp{{1,2,8,9},{4,7,12,15}};
    bool res = binary_search.Find(7,temp);
}

void SortMethodTest1() {
    std::vector<int> temp = {1,3,2,5,0};
    niu_ke::SortMethod sort;
    // sort.MpSort(temp);
    sort.InsertSort(temp);
}

int main(int argc, char *argv[])
{
    // test_twoSum();
    // test_reverseString();
    // TestsortedSquares();
    // Testrotate();
    // TestsortedSquaresnew();
    // NiuKeTest1();
    // NiuKeTest4();
    // BinarySearchTest1();
    // SortMethodTest1();
    BinarySearchTest2();
    std::cout<<"come on livie" << std::endl;
    return 0;
}
