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

// Reverse Integer, refrerence: leetCode.com
// Given a 32 - bit signed integer, reverse digits of an integer.
// Example 1:
// Input: 123
// Output : 321
// Example 2 :
// Input : -123
// Output : -321
// Example 3 :
// Input : 120
// Output : 21
// Note :
// Assume we are dealing with an environment which could only hold integers within the 32 - bit 
// signed integer range.For the purpose of this problem, assume that your function returns 0 when 
// the reversed integer overflows.
int reverse(int x)
{
    int result = 0;
    while (x)
    {
        int temp = result * 10 + x % 10;

        if (temp / 10 != result)
            return 0;

        x /= 10;
        result = temp;
    }
    return result;
}

// String to integer (atoi), refrence: LeetCode.com
// Implement atoi to convert a string to an integer.
//
// Hint:
// Carefully consider all possible input cases.If you want a challenge,
// please do not see below and ask yourself what are the possible input cases.
//
// Notes:
// It is intended for this problem to be specified vaguely(ie, no given input specs).
// You are responsible to gather all the input requirements up front.
//
// Requirements for atoi:
// The function first discards as many whitespace characters as necessary until the first
// non - whitespace character is found.Then, starting from this character, takes an optional
// initial plus or minus sign followed by as many numerical digits as possible,
// and interprets them as a numerical value.
// The string can contain additional characters after those that form the integral number,
// which are ignored and have no effect on the behavior of this function.
// If the first sequence of non - whitespace characters in str is not a valid integral number,
// or if no such sequence exists because either str is empty or it contains only whitespace characters,
// no conversion is performed.
// If no valid conversion could be performed, a zero value is returned.If the correct value is out of the range
// of representable values, INT_MAX(2147483647) or INT_MIN(-2147483648) is returned.
int myAtoi(string str)
{
    if (str == "")
    {
        return 0;
    }

    int c = 0;
    int result = 0;
    bool negative = false;
    int len = str.length();

    while (c < len  && str[c] == ' ')
    {
        c++;
    }

    if (c < len && (str[c] == '+' || str[c] == '-'))
    {
        if (str[c] == '-')
            negative = true;
        c++;
    }

    while (c < len && str[c] == '0')
    {
        c++;
    }

    while (c < len && str[c] >= '0' && str[c] <= '9')
    {
        int temp = (result * 10) + str[c] - '0';

        if (temp / 10 == result)
        {
            result = temp;
            c++;
        }
        else
        {
            return negative ? INT_MIN : INT_MAX;
        }
    }
    return  negative ? result * -1 : result;
}

// Palindrome Number, reference: LeetCode.com
// Determine whether an integer is a palindrome.Do this without extra space.
// For example 11011 and 1221 are palindrome and 123 is not
bool isPalindrome(int x)
{
    if (x < 0 || (x % 10 == 0 && x != 0))
        return false;

    int revX = 0;

    while (x > revX)
    {
        revX = (revX * 10) + (x % 10);
        x /= 10;
    }
    return (x == revX || x == revX / 10);
}

// Remove Nth Node From End of List, reference: LeetCode.com
// Given a linked list, remove the nth node from the end of list and return its head.
//
// For example,
// Given linked list : 1->2->3->4->5, and n = 2.
// After removing the second node from the end, the linked list becomes 1->2->3->5.
//
// Note:
// Given n will always be valid.
// Try to do this in one pass.
ListNode<int>* removeNthFromEnd(ListNode<int>* head, int n)
{
    if (!head)
        return NULL;

    ListNode<int>* dummyHead = new ListNode<int>(0);
    dummyHead->next = head;
    ListNode<int>* fwd = dummyHead;
    ListNode<int>* prv = dummyHead;

    while (fwd->next && n > 0) {
        fwd = fwd->next;
        n--;
    }

    if (!fwd)
        return NULL;

    while (fwd->next)
    {
        fwd = fwd->next;
        prv = prv->next;
    }

    prv->next = prv->next->next;
    return dummyHead->next;
}

// Valid Parentheses, reference: LeetCode.com
// Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
// The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
bool isValidParentheses(string s)
{
    if (s == "")
        return true;
    stack<char> myStack;

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == ']' || s[i] == '}' || s[i] == ')')
        {
            if (s[i] == ']' && (myStack.empty() || myStack.top() != '['))
                return false;
            else if (s[i] == '}' && (myStack.empty() || myStack.top() != '{'))
                return false;
            else if (s[i] == ')' && (myStack.empty() || myStack.top() != '('))
                return false;
            else
                myStack.pop();
        }
        else
        {
            myStack.push(s[i]);
        }
    }
    return  myStack.empty();
}

// Merge Two Sorted Lists, reference: LeetCode.com
// Merge two sorted linked lists and return it as a new list. The new list should be made by
// splicing together the nodes of the first two lists.
ListNode<int>* MergeTwoLists(ListNode<int>* l1, ListNode<int>* l2)
{
    ListNode<int>* dummyHead = new ListNode<int>(0);
    ListNode<int>* head = dummyHead;

    while (l1 && l2)
    {
        if (l1->val < l2->val)
        {
            head->next = l1;
            l1 = l1->next;
        }
        else
        {
            head->next = l2;
            l2 = l2->next;
        }
        head = head->next;
    }
    head->next = (l1) ? l1 : l2;
    return dummyHead->next;
}

int main()
{
    // Test twoSum
    vector<int> nums = { 2, 7, 11, 15 };
    cout << "Sum of following two indices which is9 : ";
    Utils::PrintVector(twoSum(nums, 9));

    // Test addTwoNumbers
    // 15 + 39 = 54
    ListNode<int>* firstNumber = new ListNode<int>(5);
    firstNumber->next = new ListNode<int>(1);
    ListNode<int>* secondNumber = new ListNode<int>(9);
    secondNumber->next = new ListNode<int>(3);
    auto result = addTwoNumbers(firstNumber, secondNumber);
    cout << "15 + 39  stored in reverse order in linkedlist is: ";
    Utils::PrintLinkedList(result);

    // Test lengthOfLongestSubstring
    cout << "Lenth of longest substring of 'pwwkew' is: " << lengthOfLongestSubstring("pwwkew") << endl;

    // Test Reverse Integer
    cout << "revrse of -234 is: " << reverse(-234) << endl;

    // String to integer (atoi) test
    cout << "This is converted number for '  -000698xcd ' is: " << myAtoi("  -000698xcd ") << endl;

    // TestisPalindrome
    string palindromeOrNot = isPalindrome(1105011) ? "Palindrome" : "not Palindrome";
    cout << "Number 1105011 is: " << palindromeOrNot.c_str() << endl;

    // Test removeNthFromEnd
    ListNode<int>* linkedList = new ListNode<int>(1);
    linkedList->next = new ListNode<int>(2);
    linkedList->next->next = new ListNode<int>(3);
    ListNode<int>* res = removeNthFromEnd(linkedList, 2);
    cout << "removing second elemnt from 1->2->3 results in: ";
    Utils::PrintLinkedList(res);

    // Test isValidParentheses
    cout << "()[]{} is: ";
    if (isValidParentheses("()[]{}"))
        cout << "valid parantheses approved" << endl;
    else
        cout << "not valid parantheses approved" << endl;

    // Test MergeTwoLists
    ListNode<int>* firstList = new ListNode<int>(1);
    firstList->next = new ListNode<int>(3);
    ListNode<int>* secondList = new ListNode<int>(2);
    secondList->next = new ListNode<int>(4);
    cout << "merged sorted list of 1->3 and 2->4 is: ";
    Utils::PrintLinkedList(MergeTwoLists(firstList,secondList));

    // Kepp console waiting
    int i;
    cin >> i;
    return 0;
}