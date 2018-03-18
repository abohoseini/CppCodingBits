# Cpp Coding Bits
Here I have gathered some random coding questions and my implementation in C++. 
Please feel free to use them in any way you want. 

## Two Sum
Given an array of integers, return indices of the two numbers such that they add up to a specific target.
You may assume that each input would have exactly one solution, and you may not use the same element twice.

##### Example:
Given nums = [2, 7, 11, 15], target = 9,
Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
Refrerence: leetCode.com

## Add Two Numbers
You are given two non - empty linked lists representing two non - negative integers.
The digits are stored in reverse order and each of their nodes contain a single digit.Add the two numbers and return it as a linked list.
You may assume the two numbers do not contain any leading zero, except the number 0 itself.

##### Example:
Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation : 342 + 465 = 807.
Refrerence: leetCode.com

## Longest Substring Without Repeating Characters
Given a string, find the length of the longest substring without repeating characters.
 
#### Examples:
Given "abcabcbb", the answer is "abc", which the length is 3.
Given "bbbbb", the answer is "b", with the length of 1.
Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
Refrerence: leetCode.com

## Reverse Integer
Given a 32 - bit signed integer, reverse digits of an integer.

#### Example 1:
Input: 123
Output : 321
#### Example 2 :
Input : -123
Output : -321
#### Example 3 :
Input : 120
Output : 21

#### Note :
Assume we are dealing with an environment which could only hold integers within the 32 - bit
signed integer range.For the purpose of this problem, assume that your function returns 0 when
the reversed integer overflows.
Refrerence: leetCode.com

## String to integer (atoi)
Implement atoi to convert a string to an integer.

#### Hint:
Carefully consider all possible input cases.If you want a challenge,
please do not see below and ask yourself what are the possible input cases.

#### Notes:
It is intended for this problem to be specified vaguely(ie, no given input specs).
You are responsible to gather all the input requirements up front.

#### Requirements for atoi :
The function first discards as many whitespace characters as necessary until the first
non - whitespace character is found.Then, starting from this character, takes an optional
initial plus or minus sign followed by as many numerical digits as possible,
and interprets them as a numerical value.
The string can contain additional characters after those that form the integral number,
which are ignored and have no effect on the behavior of this function.
If the first sequence of non - whitespace characters in str is not a valid integral number,
or if no such sequence exists because either str is empty or it contains only whitespace characters,
no conversion is performed.
If no valid conversion could be performed, a zero value is returned.If the correct value is out of the range
of representable values, INT_MAX(2147483647) or INT_MIN(-2147483648) is returned.
Refrerence: leetCode.com

## Palindrome Number
Determine whether an integer is a palindrome.Do this without extra space.
For example 11011 and 1221 are palindrome and 123 is not
Refrerence: leetCode.com

## Remove Nth Node From End of List
Given a linked list, remove the nth node from the end of list and return its head.

#### For example,
Given linked list : 1->2->3->4->5, and n = 2.
After removing the second node from the end, the linked list becomes 1->2->3->5.

#### Note:
Given n will always be valid.
Try to do this in one pass.
Refrerence: leetCode.com

## Valid Parentheses
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
Refrerence: leetCode.com

## Merge Two Sorted Lists
Merge two sorted linked lists and return it as a new list. The new list should be made by
splicing together the nodes of the first two lists.
Refrerence: leetCode.com

## Validate Binary Search Tree
Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

    - The left subtree of a node contains only nodes with keys less than the node's key.
    - The right subtree of a node contains only nodes with keys greater than the node's key.
    - Both the left and right subtrees must also be binary search trees.

#### Example 1:
    2
   / \
  1   3
Binary tree [2,1,3], return true.

#### Example 2:
    1
   / \
  2   3
Binary tree [1,2,3], return false.
Refrerence: leetCode.com

## Longest Common Prefix
// Write a function to find the longest common prefix string amongst an array of strings.
Refrerence: leetCode.com