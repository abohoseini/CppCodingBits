// CppQuestions.cpp : Defines the entry point for the console application.

#include "stdafx.h"
#include "Utils.h"

//TwoSum, refrerence: leetCode.com
// Given an array of integers, return indices of the two numbers such that they add up to a specific target.
// You may assume that each input would have exactly one solution, and you may not use the same element twice.
// Example:
// Given nums = [2, 7, 11, 15], target = 9,
// Because nums[0] + nums[1] = 2 + 7 = 9,
// return[0, 1].
vector<int> twoSum(vector<int>& nums, int target)
{
    vector<int> result(2);
    map<int, int> myMap;

    for (int i = 0; i < nums.size(); i++)
    {
        myMap[nums[i]] = i;
    }

    for (int j = 0; j < nums.size(); j++)
    {
        int complement = target - nums[j];

        auto iter = myMap.find(complement);
        if (iter != myMap.end() && iter->second != j)
        {
            result[0] = j;
            result[1] = iter->second;
        }
    }
    return result;
}

//Add Two Numbers, refrerence: leetCode.com
// You are given two non - empty linked lists representing two non - negative integers.
// The digits are stored in reverse order and each of their nodes contain a single digit.Add the two numbers and return it as a linked list.
// You may assume the two numbers do not contain any leading zero, except the number 0 itself.
// Example
// Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
// Output: 7 -> 0 -> 8
// Explanation : 342 + 465 = 807.
ListNode<int>* addTwoNumbers(ListNode<int>* l1, ListNode<int>* l2)
{
    int carryOver = 0;
    ListNode<int>* sum = new ListNode<int>(0);
    ListNode<int>* num = sum;

    while (l1 || l2 || carryOver > 0)
    {
        int l1Val = (l1) ? l1->val : 0;
        int l2Val = (l2) ? l2->val : 0;
        int sumNum = l1Val + l2Val + carryOver;
        carryOver = sumNum / 10;
        num->next = new ListNode<int>(sumNum % 10);
        num = num->next;

        if (l1)
            l1 = l1->next;

        if (l2)
            l2 = l2->next;
    }
    return sum->next;
}

// Longest Substring Without Repeating Characters, Refrence: LeetCode.com
// Given a string, find the length of the longest substring without repeating characters.
// Examples:
// Given "abcabcbb", the answer is "abc", which the length is 3.
// Given "bbbbb", the answer is "b", with the length of 1.
// Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
int lengthOfLongestSubstring(string s)
{
    int len = s.length();

    if (len == 0)
        return 0;

    int i = 0, j = 0, ans = 0;
    set<char> mySet;
    while (i < len && j < len)
    {
        auto iter = mySet.find(s[j]);
        if (iter == mySet.end())
        {
            mySet.insert(s[j]);
            j++;
            ans = max(ans, j - i);
        }
        else
        {
            mySet.erase(s[i]);
            i++;
        }
    }
    return ans;
}

int main()
{
    // test twoSum
    vector<int> nums = { 2, 7, 11, 15 };
    Utils::PrintVector(twoSum(nums, 9));

    // test addTwoNumbers
    // 15 + 39 = 54
    ListNode<int>* firstNumber = new ListNode<int>(5);
    firstNumber->next = new ListNode<int>(1);

    // test lengthOfLongestSubstring
    cout << "Lenth of longest substring of 'pwwkew' is: "<< lengthOfLongestSubstring("pwwkew") << endl;

    ListNode<int>* secondNumber = new ListNode<int>(9);
    secondNumber->next = new ListNode<int>(3);
    auto result = addTwoNumbers(firstNumber, secondNumber);
    Utils::PrintLinkedList(result);
    // Kepp console waiting
    int i;
    cin >> i;
    return 0;
}