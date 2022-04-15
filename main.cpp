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
void TestsortedSquares()
{
    vector<int> nums = {-10000,-9999,-7,-5,0,0,10000};
    leetCode.sortedSquares(nums);
}

void Testrotate()
{
    vector<int> nums = {1,5,6,8,10,7};
    leetCode.rotate(nums,2);
}
int main()
{
    test_twoSum();
    test_reverseString();
    TestsortedSquares();
    Testrotate();
    std::cout<<"come on livie" << std::endl;
    return 0;

}