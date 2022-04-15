#ifndef __LEET_CODE_H__
#define __LEET_CODE_H__
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <cmath>

using namespace std;
typedef std::unordered_map<char,int> MyMap;
class LeetCode{
public:
    LeetCode(){};
    ~LeetCode(){};
    vector<int> twoSum(vector<int>& numbers, int target);
    void reverseString(vector<char>& s);
    string reverseWords(string s);
    int lengthOfLongestSubstring(string s);
    bool checkInclusion(string s1, string s2);
    vector<int> sortedSquares(vector<int>& nums);
    void rotate(vector<int>& nums, int k);
};

#endif