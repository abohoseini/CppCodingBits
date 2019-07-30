// CppQuestions.cpp : Defines the entry point for the console application.

#include "stdafx.h"
#include "Utils.h"
#include "Maze.h"


//TwoSum, reference: leetCode.com
// Given an array of integers, return indexes of the two numbers such that they add up to a specific target.
// You may assume that each input would have exactly one solution, and you may not use the same element twice.
// Example:
// Given nums = [2, 7, 11, 15], target = 9,
// Because nums[0] + nums[1] = 2 + 7 = 9,
// return[0, 1].
vector<int> twoSum(vector<int>& nums, int target)
{
    unordered_map<int, int> myMap;

    for (int i = 0; i < nums.size(); i++)
    {
		int complement = target - nums[i];

		auto iter = myMap.find(complement);
		if (iter != myMap.end())
			return { i, iter->second };

        myMap[nums[i]] = i;
    }
	return {};
}

//Add Two Numbers, reference: leetCode.com
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
		int sumNum = carryOver;
		if (l1)
		{
			sumNum += l1->val;
			l1 = l1->next;
		}

		if (l2)
		{
			sumNum += l2->val;
			l2 = l2->next;
		}

		carryOver = sumNum / 10;
		num->next = new ListNode<int>(sumNum % 10);
		num = num->next;
	}
	return sum->next;
}

// Longest Substring Without Repeating Characters, reference: LeetCode.com
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
    while (i < len)
    {
        auto iter = mySet.find(s[i]);
        if (iter == mySet.end())
        {
            mySet.insert(s[i++]);
            ans = max(ans, i - j);
        }
        else
        {
            mySet.erase(s[j++]);
        }
    }
    return ans;
}

//Median of Two Sorted Arrays, reference: leetCode.com, solution is based on: https://youtu.be/LPFhl65R7ww
//There are two sorted arrays nums1 and nums2 of size m and n respectively.
//Find the median of the two sorted arrays.The overall run time complexity should be O(log(m + n)).
//You may assume nums1 and nums2 cannot be both empty.
//
//Example 1:
//nums1 = [1, 3]
//nums2 = [2]
//The median is 2.0
//
//Example 2:
//nums1 = [1, 2]
//nums2 = [3, 4]
//The median is(2 + 3) / 2 = 2.5
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
{
	// we want to do the binary search on the smaller array to save some time.
	if (nums1.size() > nums2.size())
		return findMedianSortedArrays(nums2, nums1);

	int x = nums1.size();
	int y = nums2.size();
	int low = 0;
	int high = x;

	while (low <= high)
	{
		int partitionX = (low + high) / 2;

		// partitionY + partitionX =(x+y+1)/2);
		int partitionY = ((x + y + 1) / 2) - partitionX;

		int maxLeftOfPartitionX = (partitionX == 0) ? INT_MIN : nums1[partitionX - 1];
		int minRightOfPartitionX = (partitionX == x) ? INT_MAX : nums1[partitionX];
		int maxLeftOfPartitionY = (partitionY == 0) ? INT_MIN : nums2[partitionY - 1];
		int minRightOfPartitionY = (partitionY == y) ? INT_MAX : nums2[partitionY];

		if (maxLeftOfPartitionX <= minRightOfPartitionY && maxLeftOfPartitionY <= minRightOfPartitionX)
		{
			if ((x + y) % 2 == 0)
				return  ((double)max(maxLeftOfPartitionX, maxLeftOfPartitionY) + min(minRightOfPartitionX, minRightOfPartitionY)) / 2;
			else
				return max(maxLeftOfPartitionX, maxLeftOfPartitionY);

		}
		else if (maxLeftOfPartitionX > minRightOfPartitionY)
		{
			// positionX should move further left
			high = partitionX - 1;
		}
		else
		{
			// positionX should move further right
			low = partitionX + 1;
		}
	}

	return INT_MIN;
}

// Longest Palindromic Substring, reference: leetCode.com, solution is based on: https://www.geeksforgeeks.org/longest-palindromic-substring-set-2/
// Given a string s, find the longest palindromic substring in s.You may assume that the maximum length of s is 1000.
//
// Example 1:
// Input: "babad"
// Output : "bab"
// Note : "aba" is also a valid answer.
//
// Example 2 :
// Input : "cbbd"
// Output : "bb"
string longestPalindrome(string s)
{
	int len = s.length();

	if (len <= 1)
		return s;

	int maxLength = 1;
	int start = 0;

	for (int i = 1; i < len; i++)
	{
		int low = i - 1;
		int high = i + 1;

		while (low >= 0 && high < len && s[low] == s[high])
		{
			if (high - low + 1 > maxLength)
			{
				maxLength = high - low + 1;
				start = low;
			}

			low--;
			high++;
		}
	}

	for (int i = 1; i < len; i++)
	{
		int low = i - 1;
		int high = i;

		while (low >= 0 && high < len && s[low] == s[high])
		{
			if (high - low + 1 > maxLength)
			{
				maxLength = high - low + 1;
				start = low;
			}
			low--;
			high++;
		}
	}

	return s.substr(start, maxLength);
}

// Reverse Integer, reference: leetCode.com
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
		int popedNum = x % 10;

		// for positive numbers, result * 10 + popedNumber > INT_MAX;
		if (popedNum >= 0 && result > (INT_MAX - popedNum) / 10)
			return 0;

		// for negative numbers, result * 10 + popedNumber < INT_MIN;
		if (popedNum <= 0 && result < (INT_MIN - popedNum) / 10)
			return 0;

        x /= 10;
		result = result * 10 + popedNum;
    }
    return result;
}

// String to integer (atoi), reference: LeetCode.com
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
    bool isNegative = false;
    int len = str.length();

    while (c < len  && str[c] == ' ')
    {
        c++;
    }

    if (c < len && (str[c] == '+' || str[c] == '-'))
    {
        if (str[c] == '-')
            isNegative = true;
        c++;
    }

    while (c < len && str[c] == '0')
    {
        c++;
    }

	while (c < len && str[c] >= '0' && str[c] <= '9')
	{

		int pop = str[c] - '0';

		if (isNegative)
			pop *= -1;

		//if pop is positive, result*10 + pop > INT_MAX -> overflow
		if (pop >= 0 && result > (INT_MAX - pop) / 10)
			return  INT_MAX;

		//if pop is negative, result*10 + pop < INT_MIN -> overflow
		if (pop <= 0 && result < (INT_MIN - pop) / 10)
			return INT_MIN;

		result = (result * 10) + pop;
		c++;
	}
    return  result;
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

// Regular Expression Matching, reference: LeetCode.com
//Given an input string(s) and a pattern(p), implement regular expression matching with support for '.'and '*'.
//
//'.' Matches any single character.
//'*' Matches zero or more of the preceding element.
//The matching should cover the entire input string(not partial).
//
//Note:
//s could be emptyand contains only lowercase letters a - z.
//p could be emptyand contains only lowercase letters a - z, and characters like . or *.
//
//Example 1 :
//Input :
//s = "aa"
//p = "a"
//Output : false
//Explanation : "a" does not match the entire string "aa".
//
//Example 2 :
//Input :
//s = "aa"
//p = "a*"
//Output : true
//Explanation : '*' means zero or more of the preceding element, 'a'.Therefore, by repeating 'a' once, it becomes "aa".
//
//Example 3 :
//Input :
//s = "ab"
//p = ".*"
//Output : true
//Explanation : ".*" means "zero or more (*) of any character (.)".
//
//Example 4 :
//Input :
//s = "aab"
//p = "c*a*b"
//Output : true
//Explanation : c can be repeated 0 times, a can be repeated 1 time.Therefore, it matches "aab".
//
//Example 5 :
//Input :
//s = "mississippi"
//p = "mis*is*p*."
//Output : false
bool isMatch(string s, string p)
{
	if (p.length() == 0)
		return s.length() == 0;

	bool firstMatch = (s.length() > 0) && (s[0] == p[0] || p[0] == '.');

	if (p.length() >= 2 && p[1] == '*')
		return isMatch(s, p.substr(2)) || (firstMatch && s.length() > 0 && isMatch(s.substr(1), p));
	else
		return firstMatch && s.length() > 0 && isMatch(s.substr(1), p.substr(1));
}

//Container With Most Water, reference: leetcode.com
//
//Given n non - negative integers a1, a2, ..., an, where each represents a point at coordinate(i, ai).n vertical lines are drawn such that the two endpoints of line i is at(i, ai) and (i, 0).
//Find two lines, which together with x - axis forms a container, such that the container contains the most water.
//
//Note: You may not slant the container and n is at least 2.
//
//Example:
//Input: [1, 8, 6, 2, 5, 4, 8, 3, 7]
//Output : 49
int maxArea(vector<int>& height) {

	int maxA = 0;
	int i = 0;
	int j = height.size() - 1;


	while (j - i > 0) {
		// or you can say while (i < j )    
		maxA = max(maxA, (min(height[i], height[j]) * (j - i)));

		if (height[i] < height[j])
			i++;
		else
			j--;
	}
	return maxA;
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

bool isValidBSTRec(TreeNode* root, TreeNode* minNode, TreeNode* maxNode)
{
    if (!root)
        return true;

    if ((minNode && root->val <= minNode->val) || (maxNode && root->val >= maxNode->val))
        return false;

    return isValidBSTRec(root->left, minNode, root) && isValidBSTRec(root->right, root, maxNode);
}

// Validate Binary Search Tree, reference: LeetCode.com
// Given a binary tree, determine if it is a valid binary search tree(BST).
// Assume a BST is defined as follows :
//  - The left subtree of a node contains only nodes with keys less than the node's key.
//  - The right subtree of a node contains only nodes with keys greater than the node's key.
//  - Both the left and right subtrees must also be binary search trees.
//
// Example 1:
//
//   2
//  / \
// 1   3
//
// Binary tree[2, 1, 3], return true.
//
// Example 2:
//
//   1
//  / \
// 2   3
//
// Binary tree[1, 2, 3], return false.
bool isValidBST(TreeNode* root)
{
    if (!root)
        return true;

    return isValidBSTRec(root, NULL, NULL);
}

string longestCommonPrefix(string l, string r)
{
    int minLen = min(l.length(), r.length());

    for (int i = 0; i < minLen; i++)
    {
        if (l[i] != r[i])
            return l.substr(0, i);
    }
    return l.substr(0, minLen);
}

string longestCommonPrefix(vector<string>& strs, int l, int r)
{
    if (l == r)
        return strs[l];
    int mid = (l + r) / 2;

    string lcpLeft = longestCommonPrefix(strs, l, mid);
    string lcpRight = longestCommonPrefix(strs, mid + 1, r);

    return longestCommonPrefix(lcpLeft, lcpRight);
}

// Longest Common Prefix, reference: LeetCode.com
// Write a function to find the longest common prefix string amongst an array of strings.
string longestCommonPrefix(vector<string>& strs)
{
    if (strs.size() == 0)
        return "";

    return longestCommonPrefix(strs, 0, strs.size() - 1);
}

struct Interval
{
    int start;
    int end;
    Interval(int s, int e) : start(s), end(e) {}
};

bool comparer(Interval a, Interval b) { return (a.start < b.start); }

// Minimum Meeting Rooms Number
// Given an array of meeting tine intervals of start and end times [[s1,e1],[s2,e2][s3,e3],...] (si < ei),
// find the minimum number of conference room required.
// for example,
// Given [[0, 30], [5, 10][15, 20]]
// return 2.
int minMeetingRooms(vector<Interval>& intervals)
{
    if (intervals.size() ==0)
        return 0;

    std::sort(intervals.begin(), intervals.end(), comparer);

    priority_queue<int,vector<int>, greater<int>> myQ;
    myQ.push(intervals[0].end);

    for (int i = 1; i < intervals.size(); i++)
    {
        if (intervals[i].start >= myQ.top())
            myQ.pop();

        myQ.push(intervals[i].end);
    }
    return myQ.size();
}

int main()
{
    // Test twoSum
    vector<int> nums = { 2, 7, 11, 15 };
    cout << "In following vector: " << "{ 2, 7, 11, 15 }" << " Sum of following two indexes is 9: ";
    Utils::PrintVector(twoSum(nums, 9));

	cout << endl;

    // Test addTwoNumbers
    // 15 + 39 = 54
    ListNode<int>* firstNumber = new ListNode<int>(5);
    firstNumber->next = new ListNode<int>(1);
    ListNode<int>* secondNumber = new ListNode<int>(9);
    secondNumber->next = new ListNode<int>(3);
    auto result = addTwoNumbers(firstNumber, secondNumber);
    cout << "15 + 39  stored in reverse order in linked-list is: ";
    Utils::PrintLinkedList(result);

	cout << endl;

    // Test lengthOfLongestSubstring
    cout << "Length of longest substring of 'pwwkew' is: " << lengthOfLongestSubstring("pwwkew") << endl;

	cout << endl;

	// Test findMedianSortedArrays
	vector<int> nums1 = { 1 , 2 };
	vector<int> nums2 = { 3 , 4 };
	cout << " The Median of following sorted arrays of " << Utils::VectorToString<int>(nums1) << " and " << Utils::VectorToString<int>(nums2) << " is: " << findMedianSortedArrays(nums1, nums2) << endl;

	cout << endl;

	// Test longestPalindrome
	cout << "The longest palindromic substring of 'babad' is: " << longestPalindrome("babad") << endl;

	cout << endl;

    // Test Reverse Integer
    cout << "reverse of -234 is: " << reverse(-234) << endl;

	cout << endl;

    // String to integer (atoi) test
    cout << "This is converted number for '  -000698xcd ' is: " << myAtoi("  -000698xcd ") << endl;

	cout << endl;

    // Test isPalindrome
	int num = 1105011;
    string palindromeOrNot = isPalindrome(num) ? "Palindrome" : "not Palindrome";
    cout << "Number " << num << " is:  " << palindromeOrNot.c_str() << endl;

	cout << endl;

	//Test isMatch
	string s = "mississippi";
	string p = "mis*is*p*.";

	string matches = isMatch(s, p) ? " matches" : " doesn't match"; 
	cout << "The sting: " << s << matches<< " the string: "<< p << endl;

	cout << endl;

	// Test maxArea
	vector<int> Heights = { 1, 8, 6, 2, 5, 4, 8, 3, 7 };

	cout << "The max area occupied between following heights in order: " << Utils::VectorToString<int>(Heights) << " is: " << maxArea(Heights) << endl;

	cout << endl;

    // Test removeNthFromEnd
    ListNode<int>* linkedList = new ListNode<int>(1);
    linkedList->next = new ListNode<int>(2);
    linkedList->next->next = new ListNode<int>(3);
    ListNode<int>* res = removeNthFromEnd(linkedList, 2);
    cout << "removing second element from 1->2->3 results in: ";
    Utils::PrintLinkedList(res);

	cout << endl;

    // Test isValidParentheses
    cout << "()[]{} is: ";
    if (isValidParentheses("()[]{}"))
        cout << "valid parentheses approved" << endl;
    else
        cout << "not valid parentheses approved" << endl;

	cout << endl;

    // Test MergeTwoLists
    ListNode<int>* firstList = new ListNode<int>(1);
    firstList->next = new ListNode<int>(3);
    ListNode<int>* secondList = new ListNode<int>(2);
    secondList->next = new ListNode<int>(4);
    cout << "merged sorted list of 1->3 and 2->4 is: ";
    Utils::PrintLinkedList(MergeTwoLists(firstList, secondList));

	cout << endl;

    // Test isValidBST
    TreeNode* tree = new TreeNode(2);
    tree->left = new TreeNode(1);
    tree->right = new TreeNode(3);
    cout << "tree [1 2 3] is a ";
    isValidBST(tree) ? cout << "Valid BST" << endl : cout << "Invalid BST" << endl;

	cout << endl;

    // Test longestCommonPrefix
    vector<string> strs = { "abo", "ab", "abolfazl" };
    cout << "Longest common prefix for {abo, ab, abolfazl} is: " << longestCommonPrefix(strs).c_str() << endl;

	cout << endl;

    // Test Maze
    //0 0 1 0 0
    //0 0 0 0 0
    //0 0 0 1 0
    //1 1 0 1 1
    //0 0 0 0 0
    vector<vector<bool>> board1 = { { false, false, true, false, false },
    { false, false, false, false, false },
    { false, false, false, true, false },
    { true, true, false, true, true },
    { false, false, false, false, false } };

    Maze maze(board1, coordinate{ 0,4 }, coordinate{ 4,4 });
    if (maze.FindCheese())
        maze.PrintBoardAndPath();

	cout << endl;

    // Test minMeetingRooms
    vector<Interval> meetings = { Interval(0,30),Interval(5,10), Interval(15, 20) };
    cout << "Minimum number of meeting rooms for meeting [0, 30], [5, 10][15, 20]] is: " << minMeetingRooms(meetings) << endl;

    // Keep console waiting
    int i;
    cin >> i;
    return 0;
}