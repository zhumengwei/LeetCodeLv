#include "include/leet_code.h"
#include <iostream>
LeetCode leetCode;
void test_twoSum()
{
    
    vector<int> numbers = {0,1,2,5,6};
    vector<int> res = leetCode.twoSum(numbers,3);
}
void test_reverseString()
{
    vector<char> s = {'h','e','l','l','o'};
    leetCode.reverseString(s);
    //leetCode.lengthOfLongestSubstring("abcaefb");
    leetCode.lengthOfLongestSubstring("abba");
    leetCode.checkInclusion("ab","a");
}
void TestsortedSquaresnew()
{
    vector<int> nums = {-10000,-9999,-7,-5,0,0,10000};
    leetCode.sortedSquares(nums);
}

void Testrotate()
{
    vector<int> nums = {1,5,6,8,10,7};
    leetCode.rotate(nums,2);
}
// int main()
void TestsortedSquares() {
    vector<int> nums = {-4,-1,0,3,10};
    leetCode.sortedSquaresnew(nums);
}

void TestMidNode() {
    vector<int> nums{2,5,6,3};
    auto head = leetCode.transforArray2List(nums);
    leetCode.deleteList(head);
}

int main(int argc, char *argv[])
{
    test_twoSum();
    test_reverseString();
    TestsortedSquares();
    Testrotate();
    TestsortedSquaresnew();
    TestMidNode();
    std::cout<<"come on livie" << std::endl;
    return 0;
}