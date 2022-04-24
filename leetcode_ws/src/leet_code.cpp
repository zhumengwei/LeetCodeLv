#include "../include/leet_code.h"


vector<int> LeetCode::twoSum(vector<int>& numbers, int target)
{
    vector<int> result;
    
        for(vector<int>::iterator iter = numbers.begin();iter!= numbers.end();++iter)
        {
            int searchVal = target - *iter;
            vector<int>::iterator iter1 = iter +1;
            vector<int>::iterator iter2 = numbers.end()-1;
            
            while(iter1<iter2-1)
            {
                vector<int>::iterator miditer = iter1+static_cast<int>((iter2-iter1)/2);
                if(*miditer == searchVal)
                {
                    result.push_back(iter - numbers.begin()+1);
                    result.push_back(miditer - numbers.begin()+1);
                    return result;
                }
                else if(searchVal>=*miditer  )
                {
                    iter1 = miditer +1;
                }
                else
                {
                    iter2 = miditer -1;
                }
            } 
            if(*iter1 == searchVal)
            {
                result.push_back(iter - numbers.begin()+1);
                result.push_back(iter1 - numbers.begin()+1);
                return result;
            }
            else if(*iter2 == searchVal)
            {
                result.push_back(iter - numbers.begin()+1);
                result.push_back(iter2 - numbers.begin()+1);
                return result;   
            }           
        }
        return result;
}

void LeetCode::reverseString(vector<char>& s)
{
    auto iter1 = s.begin();
    auto iter2 = s.end()-1;
    while(iter1 < iter2)
    {
        char temp = *iter1;
        *iter1 = *iter2;
        *iter2 = temp;
        ++iter1;
        --iter2;
    }
}

// string LeetCode::reverseWords(string s)
// {
//     auto iter1 = s.begin();
    
// }
int LeetCode::lengthOfLongestSubstring(string s)
{
    std::unordered_map<char,int> temp_map;
    int len = s.length();
    int index1 = 0,index2 = 0, max_length = 0;
    for(int i=0;i<len;i++)
    {
        auto it = temp_map.find(s[i]);
        if(it== temp_map.end())
        {
            temp_map.insert(std::make_pair(s[i],i)); 
            index2 = i;                      
        }
        else{
            max_length = std::max((index2 - index1+1),max_length);
            index1 = it->second +1 > index1 ? it->second +1 : index1;
            index2 = i;
            it->second = i;          
        }
    }
    max_length = std::max((index2 - index1+1),max_length);
    return max_length;
}
//
bool LeetCode::checkInclusion(string s1, string s2)
{
    int len1 = s1.length();
    int len2 = s2.length();
    if(len1 > len2) return false;
    vector<int> cnt1(26,0),cnt2(26,0);
    for(int i=0;i<len1;i++)
    {
        ++cnt1[s1[i]-'a'];
        ++cnt2[s2[i]-'a'];
    }
    if(cnt1 == cnt2) return true;
    for(int i=len1;i<len2;i++)
    {
        ++cnt2[s2[i]-'a'];
        --cnt2[s2[i-len1]-'a'];
        if(cnt1 == cnt2) return true;
    }
    return false;

    // if(s2.find(s1)!=string::npos)
    // {
    //     return true;
    // }
    // else{
    //     reverse(s1.begin(),s1.end());
    //     if(s2.find(s1) != true)
    //     {
    //         return true;
    //     }

    // }
    // return false;
    // std::unordered_map<char,int> s1_map;
    // int s1_len = s1.length();
    // for(int i=0;i<s1.length();i++)
    // {
    //     auto it = s1_map.find(s1[i]);
    //     if(it == s1_map.end())
    //     {
    //         s1_map.insert(std::make_pair(s1[i],1));
    //     }
    //     else{
    //         it->second++;
    //     }
    // }
    // std::unordered_map<char,int> s2_map;
    // int index1 = 0,index2 = s1_len,s2_len = s2.length();
    // bool res;
    // for(int i = 0; i< s2_len;i++)
    // {
    //     res = true;
    //     index2 = i;
    //     auto it = s2_map.find(s2[i]);
    //     if(it == s2_map.end())
    //     {
    //         s2_map.insert(std::make_pair(s2[i],1));
    //     }
    //     else{
    //         it->second++;
    //     }
    //     if(index2 - index1 +1 == s1_len)
    //     {
    //         if(s1_map.size()==s2_map.size())
    //         {
    //             for(auto it1=s1_map.begin();it1!=s1_map.end();++it1)
    //             {
    //                 auto it2 = s2_map.find(it1->first);
    //                 if(it2 ==s2_map.end()|| (it2!= s2_map.end() && it2->second != it1->second))
    //                 
    //                     res = false;
    //                     break;
    //                 }                      
    //             }
    //         }
    //         else{
    //             res = false;
    //         }
    //         if(res)
    //         {
    //             return res;
    //         }
    //         else{
    //             auto it = s2_map.find(s2[index1]);
    //             if(it->second == 1)
    //             {
    //                 s2_map.erase(it);
    //             }
    //             else{
    //                 it->second--;
    //             }
    //             index1++;
    //         }
    //     }    
    // }
    // return res;
}

vector<int> LeetCode::sortedSquares(vector<int>& nums)
{
    int size = nums.size();
    vector<int> res;
    int pt1 = -1;
    int pt2 = size;
    //find the frist pos bigger than zero
    if(nums[0] >= 0)
    {
        pt2 = 0;
    }
    else if(nums[size -1]<=0)
    {
        pt1 = size -1;
    }
    else
    {
        for(int i = 0;i<size;i++)
        {
            if(nums[i]>=0)
            {
                pt2 = i;
                pt1 = i-1;
                break;           
            }
        }
    }
    while(pt1>=0 || pt2 < size)
    {
        int val1 = pt1>=0?pow(nums[pt1],2):pow(10001,2);
        int val2 = pt2<size?pow(nums[pt2],2):pow(10001,2);
        if(val1<=val2)
        {
            res.push_back(val1);
            pt1 --;
        }
        else{
            res.push_back(val2);
            pt2++;
        }
    }
    return res;
}

void LeetCode::rotate(vector<int>& nums, int k)
{
    int size = nums.size();
    if(k%size == 0)
    {
        return;
    }
    vector<int> temp;
    int pt1 = 0;
    int pt2 = size - k;
    int pt = pt2;
    while(pt<size)
    {
        temp.push_back(nums[pt]);
        pt ++;
    }
    while(pt1 < pt2)
    {
        temp.push_back(nums[pt1]);
        pt1++;
    }
    nums.assign(temp.begin(),temp.end());
    return;
}

vector<int> LeetCode::sortedSquaresnew(vector<int>& nums) {
   int pleft = 0,pright = 0;
   int size = nums.size();
   // corner case nums[0] > 0
   if(nums[0]>=0) {
       pright = 0;
       pleft = -1;
   } else if(nums[size -1]<=0) {
       // nums.end <= 0
       pleft = size - 1;
       pright = size;
   } else {
       for (int i = 0;i < size; i++) {
           if (nums[i] >= 0) {
               pright = i;
               pleft = i-1;
               break;
           }
       }
   }
   // sort square by two ptr
   vector<int> res;
   const int kMaxVal = 100000001;
   while(pleft >= 0 || pright < size) {
       int val_left = pleft >= 0 ? std::pow(nums[pleft],2) : kMaxVal;
       int val_right = pright < size ? std::pow(nums[pright],2) : kMaxVal;
       if(val_left <= val_right) {
           res.push_back(val_left);
           pleft--;
       } else {
           res.push_back(val_right);
           pright++;
       }
   }
   return res;

}

ListNode* LeetCode::transforArray2List(vector<int>& nums) {
   if (nums.empty()) {
       return nullptr;
   } else {
       ListNode *head = nullptr;
       ListNode *cur_node = nullptr;
       int index = 0;
       while(index < nums.size()) {
           if(head) {
               ListNode *temp = new ListNode(nums[index]);
               cur_node->next = temp;
               cur_node = cur_node->next;
           } else {
               head = new ListNode(nums[index]);
               cur_node = head;
           }
           index++;
       }
    return head;
   }
}
ListNode* LeetCode::middleNode(ListNode* head) {
    return nullptr;
}

void LeetCode::deleteList(ListNode* head) {
    ListNode *test_node = head;
    ListNode *cur_node = head;
    while(cur_node) {
        ListNode *temp = cur_node;
        cur_node = cur_node->next;
        delete temp;
    }
}